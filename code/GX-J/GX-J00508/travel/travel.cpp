#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,s='';
    int n=0,m=0,x=0;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        s+='1';
    }
    else{
        s+='0';
        n=1;
    }
    if(b[0]==d[0]&&a[1]==a[1]&&n==0)
    {
        s+='1';
    }
    else
    {
        s+='0';
        m=1;
    }
    if(((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))&&n==0&&m==0)
    {
        s+='1';
    }
    else
    {
        s+='0';
        x=1;
    }
    if(((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B'))&&n==0&&m==0&&x==0)
    {
        s+='1';
    }
    else
    {
        s+='0';
    }
    cout<<s;
    return 0;
}
