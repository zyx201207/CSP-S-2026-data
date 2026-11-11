#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000010];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c, t, n, d;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x[i];
            if (i >= 3 && x[i] - x[i - 1] != x[i - 1] - x[i - 2])
            {
                flag = false;
            }
        }
        if (flag)
        {
            int k = x[2] - x[1];
            int t = d / k;//；x1-x2距离差为2t - 1才有两条
            if (t == 1) cout << 0 << "\n";
            else cout << n - (2 * t) + 1 << "\n";
        }

    }
    return 0;
}
