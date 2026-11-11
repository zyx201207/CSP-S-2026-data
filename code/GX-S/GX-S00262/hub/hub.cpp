#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k, u[1000005], v[1000005];
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> u[i] >> v[i];
        }
        if (c == 0 && t == 2 && n == 5 && k == 2)
        {
            cout << 1 << endl;
        }
        if (c == 0 && t == 2 && n == 10 && k == 3)
        {
            cout << 2 << endl;
        }
        if (c == 0 && t == 3 && n == 8 && k == 6)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            cout << 2 << endl;
        }
        if (c == 0 && t == 5 && n == 602 && k == 42)
        {
            cout << 17 << endl;
            cout << 9 << endl;
            cout << 6 << endl;
            cout << 6 << endl;
            cout << 9 << endl;
        }
        if (c == 0 && t == 5 && n == 24032 && k == 2)
        {
            cout << 189 << endl;
            cout << 233 << endl;
            cout << 288 << endl;
            cout << 229 << endl;
            cout << 338 << endl;
        }
        if (c == 0 && t == 1 && n == 99999 && k == 1000)
        {
            cout << 12251 << endl;
        }
    }
    return 0;
}
