#include<bits/stdc++.h>
using namespace std;

int a,c;
string b,d;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(b[2]=='D' or b[2]=='F')
    {
        if(d[2]=='D' or d[2]=='F')
        {

        }
    }

    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }

    if(b[0]==d[0] and b[1]==d[1])
    {
        if(b[2]=='A' and d[2]=='B')
        {
            cout<<"1111";
            return 0;
        }
        if(b[2]=='C' and d[2]=='B')
        {
            cout<<"1111";
            return 0;
        }
        if(b[2]=='B' and d[2]=='A')
        {
            cout<<"1111";
            return 0;
        }
        if(b[2]=='B' and d[2]=='C')
        {
            cout<<"1111";
            return 0;
        }
        if(b[2]=='A' and d[2]=='C')
        {
            cout<<"1110";
            return 0;
        }
        if(b[2]=='C' and d[2]=='A')
        {
            cout<<"1110";
            return 0;
        }
        if(b[2]=='D' and d[2]=='F')
        {
            cout<<"1111";
            return 0;
        }
        if(b[2]=='F' and d[2]=='D')
        {
            cout<<"1111";
            return 0;
        }
        cout<<"1100";
        return 0;
    }

    cout<<"1000";
    return 0;
}
