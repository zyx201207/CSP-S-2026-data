#include <bits/stdc++.h>
using namespace std;
int a, b, d, e;
string c, s;
char n, m;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> c >> b >> s;
    if (a == b)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }
    for (int i = 0; i <= 2; i++)
    {
        if (i == 0)
        {
            d += c[i] * 10;
            e += s[i] * 10;
        }
        else if (i == 1)
        {
            d += c[i];
            e += s[i];
        }
        else
        {
            n = c[i];
            m = s[i];
        }
    }
    if (d == e)
    {
        cout << "1";
    }
    else
    {
        cout << "000";
        return 0;
    }
    if (((n == 'A' || n == 'B') && !(m == 'A' || m == 'B')) || ((m == 'A' || m == 'B') && !(n == 'A' || n == 'B')))
    {
        cout << "00";
        return 0;
    }
    else
    {
        cout << "1";
        if (abs((n - 'A') - (m - 'A') == 1)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    return 0;
}
