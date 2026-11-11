#include<bits/stdc++.h>
using namespace std;
int check(string s){
    if(s[2]=='A')return 1;
    if(s[2]=='B')return 2;
    if(s[2]=='C')return 4;
    if(s[2]=='D')return 8;
    if(s[2]=='F')return 16;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<0<<0<<0<<0;
        return 0;
    }
    cout<<1;
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<0<<0<<0;
        return 0;
    }
    cout<<1;
    int num=check(s1)+check(s2);
    if(num>8&&num!=24){
        cout<<0<<0;
        return 0;
    }
    cout<<1;
    if(num==3||num==6||num==24)cout<<1;
    else cout<<0;
    return 0;
}