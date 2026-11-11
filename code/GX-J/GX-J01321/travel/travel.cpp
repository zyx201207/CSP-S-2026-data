#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,a,b;
    cin>>a>>n>>b>>m;
    if(a==b)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if (n/10==m/10)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(n%10<='C' && m%10<='C')
    {
        cout<<"1";
    }
    else if(n%10>='C' && m%10>='C')
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if (n%10=='A')
    {
        if (m%10=='B')
        {
            cout<<"1";
        }
    }
    else if(n%10=='B')
    {
        if(m%10=='A' || m%10=='C')
        {
            cout<<"1";
        }
    }
    else if(n%10=='C')
    {
        if (m%10=='B')
        {
            cout<<"1";
        }
    }
    else if(n%10=='D')
    {
        if (m%10=='E')
        {
            cout<<"1";
        }
    }
    else if(n%10=='E')
    {
        if(m%10=='D')
        {
            cout<<"1";
        }
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
