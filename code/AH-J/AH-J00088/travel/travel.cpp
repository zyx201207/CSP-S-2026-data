#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a,b,c,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    a=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    b=(s[0]-'0')*10+(s[1]-'0');
    e=s[2];
    cin>>s;
    c=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    d=(s[0]-'0')*10+(s[1]-'0');
    f=s[2];
    if(a==c) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b==d) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((e<='C'&&f<='C')||(e>='D'&&f>='D')) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='C'&&f=='B')||(e=='B'&&f=='C')||(e=='D'&&f=='F')||(e=='F'&&f=='D')) cout<<1;
    else cout<<0;
    return 0;
}
