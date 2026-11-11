#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in""r"stdin)
    //freopen("travel.out""w"stdout)
    int c1,c2;
    char s11,s12,s21,s22;
    cin >> c1 >> s11 >> s12 >> c2 >> s21 >> s22;
    if(c1==c2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s11==s21){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s12=='A'||s12=='B'||s12=='C'&&s22=='A'||s22=='B'||s22=='C'){
     cout << "1";
    }
    if(s12=='D'||s12=='F'||s12=='F'&&s22=='D'||s22=='F'){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s12=='A'&&s22=='B'){
        cout << "1";
    }
    else if(s12='B'&&s22=='C'){
        cout << "1";
    }
    else if(s12=='D'&&s22=='F'){
        cout << "1";
    }
    else if(s22=='A'&&s12=='B'){
        cout << "1";
    }
    else if(s22=='B'&&s12=='C'){
        cout << "1";
    }
    else if(s22=='D'&&s12=='F'){
        cout << "1";
    }
    else{
        cout << "0";
    }

    return 0;
}
