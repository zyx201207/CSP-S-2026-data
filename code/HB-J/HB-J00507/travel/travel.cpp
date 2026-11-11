#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,y,n,m;
    int f=0;
    cin>>x>>y>>n>>m;
    if(x==n)cout<<1;
    else
    {
       cout<<"0000";
       return 0;
    }
    if(y[0]==m[0]&&y[1]==m[1])cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(y[2]<='C'&&m[2]<='C'||y[2]>'C'&&m[2]>'C')cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(!f&&abs(y[2]-m[2])==1)cout<<1;
    else cout<<0;
    return 0;
}
