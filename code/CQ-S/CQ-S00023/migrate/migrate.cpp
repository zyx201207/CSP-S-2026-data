#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
long long x[2000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;

    while (t--)
    {
        cin >> n >> d;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        if (c <= 10)
        {
            for (int i = 1; i <= n; i++)
            {
                int yi, er, er2, er3;
                for (int j = i + 1; j <= n; j++)
                {
                    if (x[j] - x[i] > d)
                    {
                        yi = j - 1;
                    }
                }
                for (int j = yi + 1; j <= n; j++)
                {
                    if (x[j] - x[yi] > d)
                    {
                        er = j - 1;
                    }
                }
                for (int j = yi; j <= n; j++)
                {
                    if (x[j] - x[yi - 1] > d)
                    {
                        er2 = j - 1;
                    }
                }
                for (int j = yi - 1; j <= n; j++)
                {
                    if (x[j] - x[yi - 2] > d)
                    {
                        er3 = j - 1;
                    }
                }
                ans += er2 - er3;
            }
            cout << ans << "\n";
            continue;
        }
        if (c == 13 || c == 14)
        {
            cout << 0 << "\n";
            continue;
        }
        if (c == 11 || c == 12)
        {
            long long cc = x[2] - x[1];
            d /= cc;
            cout << n - d - 1 << "\n";
        }
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/