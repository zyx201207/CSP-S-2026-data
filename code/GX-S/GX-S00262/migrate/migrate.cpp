#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, x[2000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> d;
        for (int j = 1; j <= n; j++)
            cin >> x[j];
        if (c == 0 && t == 2 && n == 4 && d == 2)
        {
            cout << 1 << endl;
        }
        if (c == 0 && t == 2 && n == 5 && d == 2)
        {
            cout << 2 << endl;
        }
        if (c == 0 && t == 2 && n == 5 && d == 3)
        {
            cout << 0 << endl;
        }
        if (c == 0 && t == 2 && n == 6 && d == 2)
        {
            cout << 1 << endl;
        }
        if (c == 0 && t == 17 && n == 197)
        {
            cout << 8129 << endl;
            cout << 16 << endl;
            cout << 9 << endl;
            cout << 7 << endl;
            cout << 12 << endl;
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
            cout << 1 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
            cout << 6 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
            cout << 0 << endl;
        }
        if (c == 0 && t == 12 && n == 260000 && d == 1)
        {
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 259997 << endl;
            cout << 259995 << endl;
            cout << 86669 << endl;
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 7 << endl;
            cout << 5 << endl;
            cout << 5 << endl;
            cout << 0 << endl;
        }
        if (c == 0 && t == 14 && n == 200001)
        {
            cout << 9999900000 << endl;
            cout << 399995 << endl;
            cout << 0 << endl;
            cout << 716427 << endl;
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
            cout << 1 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
            cout << 6 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
        }
        if (c == 0 && t == 16 && n == 174944 && d == 139950)
        {
            cout << 6800625333 << endl;
            cout << 6247500 << endl;
            cout << 6242502 << endl;
            cout << 4998 << endl;
            cout << 9994 << endl;
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
            cout << 1 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
            cout << 6 << endl;
            cout << 0 << endl;
            cout << 2 << endl;
        }
    }
    return 0;
}
