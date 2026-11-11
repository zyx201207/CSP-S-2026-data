#include<bits/stdc++.h>
using namespace std;

string rc,rs,xc,xs;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rs>>xc>>xs;
    bool f1=0;
    if(rc[0]==xc[0]&&rc[1]==xc[1])
    {
           cout<<1;
           f1=1;
    }
    else cout<<0;
    bool f=0;
    if(f1==1&&rs[0]==xs[0]&&rs[1]==xs[1])
    {
        cout<<1;
        f=1;
    }
    else cout<<0;
    bool f2=0;
    if(f==1&&f1==1&&((rs[2]<='C'&&xs[2]<='C'&&rs[2]>='A'&&xs[2]>='A')||(rs[2]>='D'&&xs[2]>='D'&&rs[2]<='E'&&xs[2]<='E')))
    {
        cout<<1;
        f2=1;
    }
    else cout<<0;
    int t=abs(rs[2]-xs[2]);
    if(f2==1&&t==1) cout<<1;
    else cout<<0;
    return 0;

}
