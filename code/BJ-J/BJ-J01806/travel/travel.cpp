#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000"<<endl;
        exit(0);
    }
    else
    {
        cout<<1;
    }
    if(b[0]==d[0] && b[1]==d[1])
    {
        cout<<1;
    }
    else
    {
        cout<<"000"<<endl;
        exit(0);
    }
    if((b[2]>='D' && d[2]>='D') || (b[2]<='C' && d[2]<='C'))
    {
        cout<<1;
    }
    else
    {
        cout<<"00"<<endl;
        exit(0);
    }
    if((b[2]>='D' && d[2]>='D') || ((b[2]<='C' && d[2]<='C') && abs(b[2]-d[2])==1))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
