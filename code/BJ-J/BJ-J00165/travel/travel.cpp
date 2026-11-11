#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
//08:55:44
//guanzhu bilibili dahongdou009
//guanzhu luogu 884813
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;cin>>s1>>s2>>t1>>t2;
    if(s1==t1)
    {
        a=1;
    }
    if(s2[0]==t2[0]&&s2[1]==t2[1]&&a)b=1;
    if(a&&b&&(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(t2[2]=='A'||t2[2]=='B'||t2[2]=='C'))||((s2[2]=='F'||s2[2]=='D')&&(t2[2]=='D'||t2[2]=='F')))){c=1;}
    if(a&&b&&c)
    {
        if((s2[2]=='C'&&t2[2]=='B')||(s2[2]=='B'&&t2[2]=='A')||(s2[2]=='A'&&t2[2]=='B')||(s2[2]=='B'&&t2[2]=='C')||(s2[2]=='D'&&t2[2]=='F')||(s2[2]=='F'&&t2[2]=='D'))
        d=1;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
