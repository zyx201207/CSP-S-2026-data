#include <bits/stdc++.h>
using namespace std;

char c1[2] = {},s1[3] = {},c2[2] = {},s2[3] = {};

void in ( )
{
    cin >> c1 >> s1 >> c2 >> s2;
    return;
}

bool check (char x,char y)
{
    bool tx = 0,ty = 0;
    if (x == 'A' || x == 'B' || x == 'C')
    {
        tx = 1;
    }
    if (y == 'A' || y == 'B' || y == 'C')
    {
        ty = 1;
    }
    if (tx == ty)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check0 (char x,char y)
{
    if (check(x,y) && s1[0] == s2[0] && s1[1] == s2[1])
    {
        if (x == 'E'||y == 'E')
        {
            return true;
        }
        else if (x == 'A' && (y == 'B'))
        {
            return true;
        }
        else if (x == 'B' && (y == 'A' || y == 'C'))
        {
            return true;
        }
        else if (x == 'C' && (y == 'B'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
int main ( )
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);

    in ( );

    int q[4] = {};

    if (c1[0] == c2[0] && c1[1] == c2[1])
    {
        q[0] = 1;
    }
    if (s1[0] == s2[0] && s1[1] == s2[1])
    {
        q[1] = 1;
    }

    if (q[1] == 1 && check(s1[2],s2[2]))
    {
        q[2] = 1;
    }
    if (check0(s1[2],s2[2]))
    {
        q[3] = 1;
    }

    printf("%d%d%d%d",q[0],q[1],q[2],q[3]);

    return 0;
}
