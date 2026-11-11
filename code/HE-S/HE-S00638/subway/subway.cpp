#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int N = 500 + 10, M = 5e5 + 10;

#define int long long

using pii = pair<int, int>;
using ll = long long;

#define fi first
#define se second
#define emp emplace_back

int f[N][N], k[N], c, n, m, d, q, w[M];
vector<pii> G[M];

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            int x, t; cin >> x >> t, G[x].emp(i, t);
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (auto to1 : G[i])
        {
            int x = to1.fi;
            for (auto to2 : G[i])
            {
                int y = to2.fi;
                if (x == y) continue;
                f[x][y] = f[y][x] = min(f[x][y], to1.se + to2.se);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (f[j][k] > f[j][i] + f[i][k]) f[j][k] = f[j][i] + f[i][k];
    for (int i = 1; i <= q; i++)
    {
        int ans = 0x3f3f3f3f3f3f3f3f;
        int a, b; cin >> a >> b;
        for (auto to1 : G[a])
        {
            for (auto to2 : G[b])
            {
                ans = min(ans, to1.se + to2.se + w[a] + w[b] + f[to1.fi][to2.fi]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}