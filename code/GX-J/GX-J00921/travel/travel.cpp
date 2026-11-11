#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string j1,p1,j2,p2;
    long long a;
    cin >> j1 >> p1 >> j2 >> p2;
    if(j1==j2)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }

    if(p1[0]==p2[0] && p1[1]==p2[1])
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if(p1[2]=='A' ||  p1[2]=='B' || p1[2]=='C' )
    {
        if(p1[2]!=p2[2])
        {
            if(p2[2]=='A' || p2[2]=='B' || p2[2]=='C')
            {
                cout << 1;
            }
            else
            {
                cout << "00";
                return 0;
            }
        }
    }
    if(p1[2]=='D' || p1[2]=='F')
    {
        if(p1[2]!=p2[2])
        {
            if(p2[2]=='D' || p2[2]=='F')
            {
                cout << "11";
                return 0;
            }
            else
            {
                cout << "00";
                return 0;
            }
        }
    }
    if(p1[2]=='A' && p2[2]=='B')
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        return 0;
    }
    if(p1[2]=='B' && p2[2]=='A')
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        return 0;
    }
    if(p1[2]=='B' && p2[2]=='C')
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        return 0;
    }
    if(p1[2]=='C' && p2[2]=='B')
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
