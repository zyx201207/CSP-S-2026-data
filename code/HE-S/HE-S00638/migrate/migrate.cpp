#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

// may be need fast IO?
const int N = 2e6 + 10;

#define int long long

using pii = pair<int, int>;
using ll = long long;

#define fi first
#define se second
#define emp emplace_back

int n, d, c, pre[N], T, x[N], f[N][4], g[N][2];
// 0 : f[i][j] == 2, w[i][j] != w[i + 1][j]
// 1 : f[i][j] == f[i + 1][j] == 1, w[i][j] == w[i + 1][j] && w[i + 1][j] != w[i + 2][j]
// 2 : f[i][j] == f[i + 1][j] == 1, w[i][j] == w[i + 1][j]
// 3 : f[i][j] == 1 && w[i][j] != w[i + 1][j]
// int _f[N][N], _w[N][N];

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> c >> T;
    while (T--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++)
        {
            int l = 1, r = i, pos = i;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (x[i] - x[mid] <= d) r = mid - 1, pos = mid;
                else l = mid + 1;
            }
            pre[i] = pos;
        }
        for (int i = 0; i <= n + 1; i++) f[i][0] = f[i][1] = f[i][2] = f[i][3] = 0, g[i][0] = g[i][1] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // 0
            int a = pre[i - 1], b = pre[i];
            if (i - 1 == a)
            {
                f[i - 1][3] = 1;
            }
            if (a != b)
            {
                if (b != a + 1)
                {
                    f[i - 1][0] = f[a][1];
                    if (a == i - 2) f[i - 1][0] = g[a][1];
                }
                f[i - 1][0] += f[a][0];
            }
            // 2
            if (a == b)
            {
                if (a != i - 1) f[i - 1][2] = f[a][3];
            }
            if (a < i - 1) f[i - 1][2] += i - 1 - a - 1;
            // 3
            if (a != b && a != i - 1)
            {
                f[i - 1][3] = f[a][3] + 1;
                if (a < min(b, i - 1)) f[i - 1][3] += min(b, i - 1) - a - 1;
            }
            if (a == b) f[i - 1][3] = 1;
            g[i][0] = f[b][3] + i - b;
            g[i][1] = f[b][0] + f[b][1];
            if (i == b) g[i][0] = 1, g[i][1] = 0;
            if (i <= 2) continue;
            int c = pre[i]; a = pre[i - 2], b = pre[i - 1];
            // 1
            if (c != b)
            {
                if (a == b) f[i - 2][1] = f[a][3];
                if (b < c) f[i - 2][1] += c - b - (a == b);
            }
            if (c == i - 2) g[i][1] = f[c][0] + f[c][1];
            ans += g[i][1];
        }
        // for (int i = 1; i <= n; i++) cerr << f[i][1] << ' ';
        // cerr << '\n';
        // int res = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= pre[i]; j++)
        //     {
        //         _w[i][j] = 0x3f3f3f3f3f3f3f3f;
        //         int q = 0;
        //         for (int w = pre[i]; w <= i; w++)
        //         {
        //             _w[i][j] = min(_w[i][j], _w[w][j] + 1);
        //             if (_w[i][j] == _w[w][j] + 1) q += _f[w][j];
        //         }
        //         _f[i][j] = q;
        //     }
        //     for (int j = pre[i] + 1; j <= i; j++) _f[i][j] = 1, _w[i][j] = 1;
        //     res = 0;
        //     for (int j = 1; j <= i; j++) if (_f[i][j] == 2) res++;
        //     _f[i][i] = 1, _w[i][i] = 0;
        //     // if (i > 2) cerr << res << ' ';
        // }
        // for (int i = 1; i <= n; i++)
        // {
        //     int res = 0;
        //     // for (int j = 1; j <= i; j++) if (_f[i][j] == _f[i + 1][j] && _f[i][j] == 1 && _w[i][j] == _w[i + 1][j]) ++res;
        //     // for (int j = 1; j <= i; j++) if (_f[i][j] == 2 && _w[i][j] != _w[i + 1][j]) ++res;
        //     // for (int j = 1; j <= i; j++) if (_f[i][j] == 1 && _w[i][j] != _w[i + 1][j]) ++res;
        //     for (int j = 1; j <= i; j++)
        //         if (_f[i][j] == _f[i + 1][j] && _f[i][j] == 1 && _w[i][j] == _w[i + 1][j] && _w[i + 1][j] != _w[i + 2][j]) ++res;
        //     cerr << res << ' ';
        // }
        // cerr << res << ' ' << ans << '\n';
            // for (int i = 1; i <= n; i++) cerr << f[i][3] << ' ';
        cout << ans << '\n';
    }

    return 0;
}