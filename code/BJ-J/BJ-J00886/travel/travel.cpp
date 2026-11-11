#include <bits/stdc++.h>
using namespace std;
string a[4];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    if (a[0] == a[2])
    {
        cout << 1;

        bool f = true;
        for (int i = 0; i < 2; i++)
        {
            if (a[1][i] != a[3][i])
            {
                f = false;
            }
        }
        if (f)
        {
            cout << 1;
            if ((int)('A') <= (int)(a[1][2]) && (int)(a[1][2]) <= (int)('C'))
            {
                if ((int)('A') <= (int)(a[3][2]) && (int)(a[3][2]) <= (int)('C'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else
            {
                if (a[1][2] == a[3][2])
                {
                    cout << 1;
                }
                else
                {
                    if ( (a[1][2] == 'D' && a[3][2] == 'F') || (a[1][2] == 'F' && a[3][2] == 'D') )
                    {
                        cout << 1;
                    }
                    else
                    {
                        cout << 0;
                    }
                }
            }
        }
        else
        {
            cout  << "00";
        }
    }
    else cout << "000";
    if (a[1][0] == a[3][0] && a[1][1] == a[3][1] && ( (abs( (int)(a[1][2]) - (int)(a[3][2]) ) == 1 && (int)(a[1][2]) + (int)(a[3][2]) != 135) || ( (a[1][2] == 'D' && a[3][2] == 'F') || (a[1][2] == 'F' && a[3][2] == 'D') )) )
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
