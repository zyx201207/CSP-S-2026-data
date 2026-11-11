#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)cout<<'1';
    else
    {
        cout<<"0000";
        return 0;
    }
    if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<'1';
    else
    {
        cout<<"000";
        return 0;
    }
    if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')
    {
        if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')cout<<'1';
        else
        {
            cout<<"00";
            return 0;
        }
    }
    else if(a2[2]=='D'||a2[2]=='F')
    {
        if(b2[2]=='D'||b2[2]=='F')cout<<'1';
        else
        {
            cout<<"00";
            return 0;
        }
    }
    if(a2[2]=='A')
    {
        if(b2[2]=='B')cout<<'1';
        else cout<<'0';
    }
    else if(a2[2]=='B')
    {
        if(b2[2]=='A'||b2[2]=='C')cout<<'1';
        else cout<<'0';
    }
    else if(a2[2]=='C')
    {
        if(b2[2]=='B')cout<<'1';
        else cout<<'0';
    }
    else if(a2[2]=='D')
    {
        if(b2[2]=='F')cout<<'1';
        else cout<<'0';
    }
    else if(a2[2]=='F')
    {
        if(b2[2]=='D')cout<<'1';
        else cout<<'0';
    }
    return 0;
}
