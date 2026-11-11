#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char x1[10],x2[10],y1[10],y2[10];
    cin>>x1[1]>>x1[2]>>x2[1]>>x2[2]>>x2[3]>>y1[1]>>y1[2]>>y2[1]>>y2[2]>>y2[3];
    if(x1[1]==y1[1]&&x1[2]==y1[2])
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(x2[1]==y2[1]&&x2[2]==y2[2])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    char x=x2[3],y=y2[3];
    if(x=='A')
    {
        if(y=='B')
        {
            cout<<"11";
        }
        else if(y=='C')
        {
            cout<<"10";
        }
        else
        {
            cout<<"00";
        }
    }
    else if(x=='B')
    {
        if(y=='A')
        {
            cout<<"11";
        }
        else if(y=='C')
        {
            cout<<"11";
        }
        else
        {
            cout<<"00";
        }
    }
    else if(x=='C')
    {
        if(y=='B')
        {
            cout<<"11";
        }
        else if(y=='A')
        {
            cout<<"10";
        }
        else
        {
            cout<<"00";
        }
    }
    else if(x=='D')
    {
        if(y=='E')
        {
            cout<<"11";
        }
        else
        {
            cout<<"00";
        }
    }
    else if(x=='E')
    {
        if(y=='D')
        {
            cout<<"11";
        }
        else
        {
            cout<<"00";
        }
    }
    return 0;
}
