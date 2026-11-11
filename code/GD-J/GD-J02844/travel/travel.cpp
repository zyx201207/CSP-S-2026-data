#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;


inline bool LXside(char c)
{
    if (c == 'A' || c == 'B' || c == 'C')
    {
        return 1;
    }
    if (c == 'D' || c == 'F')
    {
        return 0;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin >> c1 >> c2 >> c3 >> c4;
    bool inCX = 0;
    bool inP = 0;
    bool inSide = 0;
    bool inNear = 0;
    char rseat,xseat;
    string r_pai,x_pai;
    if (c1 == c3)
    {
        inCX = 1;
    }
    else
    {
        inCX = 0;
        goto DOGGOD;
    }
    r_pai = c2.substr(0,2);
    x_pai = c4.substr(0,2);
    if (r_pai == x_pai)
    {
        inP = 1;
    }
    else
    {
        inP = 0;
        goto DOGGOD;
    }
    rseat = c2[2];
    xseat = c4[2];
    if (LXside(rseat) == LXside(xseat))
    {
        inSide = 1;
    }
    else
    {
        inSide = 0;
        goto DOGGOD;
    }
    if (abs(rseat - xseat) == 1)
    {
        inNear = 1;
    }
    else
    {
        inNear = 0;
    }
    DOGGOD:;
    cout << inCX << inP << inSide << inNear;
    return 0;
}
