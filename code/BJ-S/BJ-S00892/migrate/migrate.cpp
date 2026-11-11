#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long
#define double long double
#define sqrt sqrtl

namespace BruteForce
{
    int a[5010], t[5010], p[5010][5010], f[5010];
    int solve()
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            t[i] = 0;
            p[i][0] = i;
            while (true)
            {
                int pos = upper_bound(a + 1, a + n + 1, a[p[i][t[i]]] + d) - a - 1;
                if (pos != p[i][t[i]])
                {
                    p[i][++t[i]] = pos;
                }
                else
                {
                    break;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!t[i])
            {
                continue;
            }
            fill(f + i + 1, f + n + 1, 0);
            f[p[i][1]] = 1;
            for (int blk = 1; blk <= t[i]; ++blk)
            {
                for (int j = p[i][blk]; j > p[i][blk - 1]; --j)
                {
                    f[j] = min(f[j] + (j == p[i][blk]? 0 : f[j + 1]), 3ll);
                    if (!t[j] || p[j][1] <= p[i][blk])
                    {
                        continue;
                    }
                    f[p[j][1]] += f[j];
                }
            }
            for (int j = i + 1; j <= n; ++j)
            {
                ans += (f[j] == 2);
            }
        }
        return ans;
    }
}

namespace SubtaskA
{
    int a[2000010];
    int solve()
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int m = upper_bound(a + 2, a + n + 1, a[1] + d) - a - 2;
        if (m <= 1)
        {
            return 0;
        }
        return max(0ll, n - (m << 1) + 1);
    }
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        if (c <= 10)
        {
            cout << BruteForce::solve() << EOL;
        }
        else if (c == 11 || c == 12)
        {
            cout << SubtaskA::solve() << EOL;
        }
        else
        {
            cout << 0 << EOL;
        }
    }
    return 0;
}
