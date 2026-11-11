#include <bits/stdc++.h>
using namespace std;
int a[2][2];
void func(string s,int *b){
    b[0]=(s[0]-'0')*10+s[1]-'0';
    b[1]=s[2];
}
int main(){
#ifndef HCX
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        func(s1,a[0]);func(s2,a[1]);
        if(a[0][0]==a[1][0]){
            cout<<"1";
            if((a[0][1]<='C'&&a[1][1]<='C')||(a[0][1]>'C'&&a[1][1]>'C')){
                cout<<"1";
                if(abs(a[0][1]-a[1][1])==1){
                    cout<<"1\n";
                }else cout<<"0\n";
            }else cout<<"00\n";
        }else cout<<"000\n";
    }else{
        cout<<"0000\n";
    }
    return 0;
}
// compile:
// g++ travel.cpp -o travel -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow 2> log.txt
// debug
// g++ travel.cpp -o travel -fsanitize=address,undefined -g -DHCX -std=c++14 -Wall -Wextra -Wconversion -Wshadow 