#include <bits/stdc++.h>
using namespace std;

int x,y;
string p1,p2;
string s1,s2;

int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> p1 >> s1 >> p2 >> s2;
    if (p1 != p2)
    {
        cout << "0000" << endl;
    }
    else if (s1[0] != s2[0] || s1[1] != s2[1])
    {
        cout << 1000 << endl;
    }
    else
    {
        char c1 = s1[2],c2 = s2[2];
        if (c1 == 'A' || c1 == 'B' || c1 == 'C')
        {
            x = 1;
        }
        else
        {
            x = 0;
        }
        if (c2 == 'A' || c2 == 'B' || c2 == 'C')
        {
            y = 1;
        }
        else
        {
            y = 0;
        }
        if (x == y)
        {
            if (c1 - 1 == c2 || c1 + 1 == c2)
            {
                cout << 1111 << endl;
            }
            else
            {
                cout << 1110 << endl;
            }
        }
        else
        {
            cout << 1100 << endl;
        }
    }
    return 0;
}
