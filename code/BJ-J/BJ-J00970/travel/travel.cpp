#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
char h1, h2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    h1 = s1[2];
    h2 = s2[2];
    if (c1[0] == c2[0] && c1[1] == c2[1])
    {
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << "1";
            if (((h1 == 'A' || h1 == 'B' || h1 == 'C') && (h2 == 'A' || h2 == 'B' || h2 == 'C')) || ((h1 == 'D' || h1 == 'F') && (h2 == 'D' || h2 == 'F')))
            {
                cout << "1";
                if (abs(h1 - h2) == 1)
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
