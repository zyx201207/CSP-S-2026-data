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
        cout<<0<<0<<0<<0;
        return 0;
    }
    for(int i=0;i<=0;i++)
    {
        if(b[i]==d[i]&&b[i+1]==d[i+1])
        {
            cout<<1;
        }
        else
        {
            cout<<0<<0<<0;
            return 0;
        }
    }
    for(int i=2;i<=2;i++)
    {
        if(b[i]>='A'&&b[i]<='C'&&d[i]>='A'&&d[i]<='C')
        {
            cout<<1;
        }
        else
        {
            cout<<0<<0;
            return 0;
        }
    }
    for(int i=2;i<=2;i++)
    {
        if(b[i]=='A'&&d[i]=='B'||b[i]=='B'&&d[i]=='C'||b[i]=='B'&&d[i]=='A'||b[i]=='C'&&d[i]=='B'||b[i]=='D'&&d[i]=='E'||b[i]=='E'&&d[i]=='D')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}
