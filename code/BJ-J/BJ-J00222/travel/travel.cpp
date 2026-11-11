#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string x,y;
    cin>>a>>x>>b>>y;
    int c=10*(x[0]-'0')+(x[1]-'0'),d=10*(y[0]-'0')+(y[1]-'0');
    char e=x[2],f=y[2];
    if(a==b)cout<<1;
    else cout<<0;
    if(a==b&&c==d)cout<<1;
    else cout<<0;
    if(a==b&&c==d&&((e<'D'&&f<'D')||(e>'C'&&f>'C')))cout<<1;
    else cout<<0;
    if(e>f)swap(e,f);
    if(a==b&&c==d&&((e=='D'&&f=='F')||(e=='A'&&f=='B')||(e=='B'&&f=='C')))cout<<1;
    else cout<<0;
    return 0;
}
