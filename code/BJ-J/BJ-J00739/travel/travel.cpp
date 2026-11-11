#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int p[6]={0,0,0,1,1,1};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    long long e,f;
    e=(b[0]-'0')*10+b[1]-'0';
    f=(d[0]-'0')*10+d[1]-'0';
    if(e!=f)
    {
        cout<<"000";
        return 0;
    }
    cout<<"1";
    e=p[b[2]-'A'];
    f=p[d[2]-'A'];
    if(e!=f)
    {
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(e==0 and ((b[2]=='A' and d[2]=='C') or (b[2]=='C' and d[2]=='A')))
    {
        cout<<"0";
        return 0;
    }
    cout<<"1";
    return 0;
}