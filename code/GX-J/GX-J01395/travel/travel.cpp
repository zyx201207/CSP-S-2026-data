#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<2;i++)
    {
        if(a[i]!=c[i])
        {
            cout<<"0000";
            return 0;
        }
    }
    for(int i=0;i<2;i++)
    {
        if(b[i]!=d[i])
        {
            cout<<"1000";
            return 0;
        }
    }
    if(b[2]=='A')
    {
        if(d[2]=='C')
        {
            cout<<"1110";
            return 0;
        }
        else if(d[2]=='D'||d[2]=='F')
        {
            cout<<"1100";
            return 0;
        }
        else if(d[2]=='B')
        {
            cout<<"1111";
            return 0;
        }
    }
    if(b[2]=='B')
    {
        if(d[2]=='D'||d[2]=='F')
        {
            cout<<"1100";
            return 0;
        }
        else
        {
            cout<<"1111";
            return 0;
        }
    }
    if(b[2]=='C')
    {
        if(d[2]=='A')
        {
            cout<<"1110";return 0;
        }
        else if(d[2]=='D'||d[2]=='F')
        {
            cout<<"1100";return 0;
        }
        else if(d[2]=='B')
        {
            cout<<"1111";return 0;
        }
    }
    if(b[2]=='D'||b[2]=='F')
    {
        if(d[2]=='A'||d[2]=='B'||d[2]=='C')
        {
            cout<<"1100";return 0;
        }
        else
        {
            cout<<"1111";return 0;
        }
    }
    return 0;
}
