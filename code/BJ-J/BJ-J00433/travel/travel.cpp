#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << "1";
        int s1_pos_y = (s1[0] - '0') * 10 + (s1[1] - '0');
        int s2_pos_y = (s2[0] - '0') * 10 + (s2[1] - '0');
        if (s1_pos_y == s2_pos_y)
        {
            cout << "1";
            char c1 = s1[2];
            char c2 = s2[2];
            if ((c1 == 'F' && (c2 == 'A' || c2 == 'B' || c2 == 'C')) || (c1 == 'D' && (c2 == 'A' || c2 == 'B' || c2 == 'C')) || (c2 == 'F' && (c1 == 'A' || c1 == 'B' || c1 == 'C')) || (c2 == 'D' && (c1 == 'A' || c1 == 'B' || c1 == 'C')))
            {
                cout << "00";
            }
            else
            {
                cout << "1";
                if ((c1 == 'F' && c2 == 'D') || (c2 == 'F' && c1 == 'D') || (c1 == 'B' && (c2 == 'C' || c2 == 'A')) || (c2 == 'B' && (c1 == 'C' || c1 == 'A')))
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
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
