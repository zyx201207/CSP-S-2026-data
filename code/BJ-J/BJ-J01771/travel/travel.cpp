#include<bits/stdc++.h>
using namespace std;
int c1, c2, x1, x2;
char num1, num2;
string s1, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    x1 = (s1[0]-'0') *10+s1[1]-'0';
    x2 = (s2[0]-'0') *10+s2[1]-'0';
    num1 = s1[2];
    num2 = s2[2];
    if(x1==x2)cout <<1;
    else cout<<0;
    if((num1>='D'&&num2>='D')||(num1<='c'&&num2<'c')){
        cout << 1;
        if(num1>='D') cout << 1;
        else if(abs(num1-num2)==1) cout << 1;
        else cout << 0;
        return 0;
    }
    else cout << 0;
    return 0;
}
