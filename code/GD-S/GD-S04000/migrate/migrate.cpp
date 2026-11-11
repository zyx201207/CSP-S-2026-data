#include <bits/stdc++.h>
#define int long long
#define fo(i, a, b) for (int i(a); i <= (b); ++i)
#define dfo(i, a, b) for (int i(a); i >= (b); --i)
#define N 505
#define M 500005
#define mod 998244353
#define INF 1e18
using namespace std;
int n, d, x[M], f[N][N], g[N][N], c;
inline void solve()
{
    cin >> n >> d;
    fo(i, 1, n)
    {
        cin >> x[i];
    }
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    if (c == 11 || c == 12)
    {
        int gx = x[2] - x[1];
        if (d <= gx)
        {
            cout << "0\n";
            return;
        }
        int num = 0;
        fo(i, 1, n + 1)
        {
            if (gx * i > d)
                break;
            num = i;
        }
        if (num >= n)
        {
            cout << "0\n";
            return;
        }
        num <<= 1, --num;
        cout << n - num << '\n';
        return;
    }
    fo(i, 1, n) fo(j, 1, n) f[i][j] = INF, g[i][j] = 0;
    fo(i, 1, n)
    {
        fo(j, 1, n)
        {
            if (abs(x[i] - x[j]) <= d)
            {
                f[i][j] = f[j][i] = g[i][j] = g[j][i] = 1;
            }
        }
    }
    fo(k, 1, n)
    {
        fo(i, 1, n)
        {
            fo(j, 1, n)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    fo(k, 1, n)
    {
        fo(i, 1, n)
        {
            fo(j, 1, n)
            {
                if (f[i][j] == f[i][k] + f[k][j])
                {
                    g[i][j] += g[i][k] * g[k][j];
                }
            }
        }
    }
    int cnt = 0;
    fo(i, 1, n)
    {
        fo(j, 1, n)
        {
            if (g[i][j] == 2)
            {
                ++cnt;
            }
            // cout << g[i][j] << ' ';
        }
        // cout << '\n';
    }
    cout << cnt / 2 << '\n';
}
signed main()
{
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> c >> T;
    while (T--)
        solve();
}
/*
感觉 24pts 挺简单的，先打了。
15:46 coding 24pts 1-6
15:55 ok 24pts
发现会了性质 A，打。
15:56 coding A 8pts 11,12
16:04 ok 8pts
16:04 32pts
跳 T2 思考
18:07 NOI LINUX correct
18:20 last check ok
*/