#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using  namespace std;

bool isOperator(char c){
    return (c == '^' || c == '*' || c == '+' || c == '-' || c == '/');
}

bool isOperand(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

string infixToPostfix(string infix){
    stack<char > myStack;
    string  postfix;
    unsigned long l = infix.length();
    for (int i = 0 ; i < l ; i++){
        if (isOperand(infix[i])){
            postfix += infix[i];
        }
        else if (infix[i] == '('){
            myStack.push('(');
        }
        else if (infix[i] == ')'){
            while (!myStack.empty() && myStack.top() != '(' ){
                char c = myStack.top();
                myStack.pop();
                 postfix += c;
            }
            if (myStack.top() == '('){
                char c = myStack.top();
                myStack.pop();
            }
        } else {
            if (!myStack.empty() ){
                while ( isOperator(infix[i]) <= isOperator(myStack.top())){
                    char c = myStack.top();
                    myStack.pop();
                    postfix += c;
                }
            }
            myStack.push(infix[i]);
        }
    }
    while (!myStack.empty()){
        char c ;
        c = myStack.top();
        myStack.pop();
        postfix += c;
    }

    return postfix;
}

string infixToPrefix(string infix){
    string prefix;
    unsigned long l;
    l = infix.size();
    reverse(infix.begin() , infix.end());
        for (int i = 0; i < l ; i++) {
            if (infix[i] == '('){
                infix[i] = ')';
                i++;
            }
            else if (infix[i] == ')'){
                infix[i] = '(';
                i++;
            }
        }

        prefix = infixToPostfix(infix);
        reverse(prefix.begin() , prefix.end());
    return prefix;
}

string prefixToInfix(string prefix){
    unsigned long l;
    string infix;
    stack<string> myStack;
    l = prefix.size();
    for (int i = l-1 ; i >= 0; i--) {
        if (isOperator(prefix[i])){
            string op1;
            string op2;
            op1 = myStack.top();
            myStack.pop();
            op2 = myStack.top();
            myStack.pop();
            myStack.push("(" + op1 + prefix[i] + op2 + ")");
        } else {
            myStack.push(string(1 , prefix[i]));
        }
    }
    infix = myStack.top();
    return infix;

}

string postfixToInfix(string postfix){
    unsigned long l ;
    string infix;
    stack<string> myStack;
    l = postfix.length();
    for (int i = 0; i < l; ++i) {
        if (isOperand(postfix[i])){
            myStack.push(string(1 , postfix[i]));
        } else {
            string op1 ;
            string op2 ;
            op1 = myStack.top();
            myStack.pop();
            op2 = myStack.top();
            myStack.pop();
            myStack.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
    infix = myStack.top();
    return infix;
}

void loop();

void menu() {
    int choice;
    string exp;
    cout<<" 1 : convert from infix to postfix"<<endl;
    cout<<" 2 : convert from infix to pretfix"<<endl;
    cout<<" 3 : convert from prefix to infix"<<endl;
    cout<<" 4 : convert from postfix to infix"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
    switch (choice){
        case 1:
            cout<<"enter your infix expression"<<endl;
            cin>>exp;
            cout<<"your postfix expression"<<endl;
            cout<<infixToPostfix(exp)<<endl;
            loop();
            break;
        case 2:
            cout<<"enter your infix expression"<<endl;
            cin>>exp;
            cout<<"your prefix expression"<<endl;
            cout<<infixToPrefix(exp)<<endl;
            loop();
            break;
        case 3:
            cout<<"enter your prefix expression"<<endl;
            cin>>exp;
            cout<<"your infix expression"<<endl;
            cout<<prefixToInfix(exp)<<endl;
            loop();
        case 4:
            cout<<"enter your postfix expression"<<endl;
            cin>>exp;
            cout<<"your infix expression"<<endl;
            cout<<postfixToInfix(exp)<<endl;
            loop();
        default:
            cout<<"sorry your choice is not here"<<endl;
            menu();
            break;

    }
}

void loop(){
    char choice ;
    cout<<" y : continue"<<endl;
    cout<<" n : Exit"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
    cout<<endl;
    while (true){
        if (choice == 'y'){
            menu();
        }
        else if (choice == 'n'){
            return;
        } else {
            cout<<"sorry your choice is not here try another choice"<<endl;
            loop();
        }
    }
}
int main() {
    menu();

    return 0;
}