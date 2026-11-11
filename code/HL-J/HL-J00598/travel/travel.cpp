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
        cout<<"1";
    }
    else cout<<"0";
    if(a==c&&b[0]==d[0]&&b[1]==d[1])
    {
        cout<<"1";
    }
    else  cout<<"0";
    if(b[2]<=67&&d[2]<=67)
    {
        if(a==c&&b[0]==d[0]&&b[1]==d[1])
        {
            cout<<"1";
        }
        else cout<<"0";
    }
    else if(b[2]>67&&d[2]>67)
    {
        if(a==c&&b[0]==d[0]&&b[1]==d[1])
        {
            cout<<"1";
        }
        else cout<<"0";
    }
    else
    {
        cout<<"0";
    }
    if(b[0]==d[0]&&b[1]==d[1]&&b[2]<=67&&d[2]<=67)
    {
        if(b[2]==65&&d[2]==66||b[2]==66&&d[2]==67||b[2]==66&&d[2]==65||b[2]==67&&d[2]==66)
        {
            cout<<"1";
        }
        else cout<<"0";
    }
    else if(b[2]>67&&d[2]>67)
    {
        if(b[2]==68&&d[2]==70||b[2]==70&&d[2]==68)
            cout<<"1";
        else cout<<"0";
    }
    else cout<<"0";
    return 0;
}
