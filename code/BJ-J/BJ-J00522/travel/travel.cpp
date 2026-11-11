#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int x=(b[0]-'0')*10+(b[1]-'0');
    int y=(d[0]-'0')*10+(d[1]-'0');
    char tx=min(b[2],d[2]),ty=max(b[2],d[2]);
    if(a!=c)   cout<<0<<0<<0<<0<<'\n';
    else if(x!=y)   cout<<1<<0<<0<<0<<'\n';
    else if(!('A'<=b[2]<='C'&&'A'<=d[2]<'=C'||'D'<=b[2]<='E'&&'D'<=d[2]<='E'))   cout<<1<<1<<0<<0<<'\n';
    else if(tx=='A'&&ty=='B'||tx=='B'&&ty=='C'||tx=='D'&&ty=='E')   cout<<1<<1<<1<<1<<'\n';
    else   cout<<1<<1<<1<<0<<'\n';
    return 0;
}