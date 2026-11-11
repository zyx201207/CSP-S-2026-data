#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(b[b.size()-1]==d[d.size()-1] and b[b.size()-2]==d[d.size()-2])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if((b[b.size()]<='C' and d[d.size()]<='C') or (b[b.size()]>='D' and d[d.size()]>='D'))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(b[b.size()-1]==d[d.size()-1]+1 or b[b.size()-1]+1==d[d.size()-1])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}

