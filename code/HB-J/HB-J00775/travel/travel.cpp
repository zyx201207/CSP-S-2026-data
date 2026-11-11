#include <bits/stdc++.h>
using namespace std;

char c1[5], c2[5], s1[5], s2[5];
int sr, sx;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    scanf ("%s %s %s %s", &c1, &s1, &c2, &s2);

    sr = int (s1[2] - 'A' + 1);
    sx = int (s2[2] - 'A'+ 1);

    if (c1[0] == c2[0] && c1[1] == c2[1])
    {
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << "1";
            if ((sr == 1 || sr == 2 || sr == 3) && (sx == 1 || sx==2 || sx == 3))
            {
                cout << "1";
                if ((sr == 1 && sx == 3) || (sr == 3 && sx == 1))
                {
                    cout << "0";
                    return 0;
                }
                else
                {
                    cout << "1";
                return 0;
                }
            }
            else if ((sr == 5|| sr == 4) && (sx == 4 || sx==5))
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
        else
        {
            cout << "000";
            return 0;
        }
    }
    else
    {
        cout << "0000";
        return 0;
    }
    return 0;
}
