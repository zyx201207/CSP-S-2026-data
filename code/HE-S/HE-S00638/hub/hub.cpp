#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

// may be need fast IO?
const int N = 1 + 10;

// #define int long long

using pii = pair<int, int>;
using ll = long long;

#define fi first
#define se second
#define emp emplace_back

int n, T, c, tot, ds[N][N], dep[N], f[N], k;
vector<int> G[N];
bool v[N];

void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1, f[x] = fa;
    for (auto to : G[x])
    {
        if (to == fa) continue;
        if (v[x] && v[to]) --tot;
        dfs(to, x);
    }
}

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
    freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> c >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1, x, y; i < n; i++) cin >> x >> y, G[x].emp(y), G[y].emp(x);
        dfs(1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int x = i, y = j;
                while (x != y)
                {
                    if (dep[x] > dep[y]) swap(x, y);
                    y = f[y];
                }
                ds[i][j] = dep[i] + dep[j] - 2 * dep[x];
            }
        }
        int res = 0x3f3f3f3f;
        for (int i = 0; i < 1 << n; i++)
        {
            for (int j = 0; j < n; j++) v[j + 1] = (i >> j) & 1;
            tot = __builtin_popcount(i);
            if (tot != k) continue;
            dfs(1, 0);
            if (tot > 2) continue;
            int tmp = 0;
            for (int a = 1; a <= n; a++)
            {
                int qwq = 0x3f3f3f3f;
                for (int b = 1; b <= n; b++)
                {
                    if (v[b]) qwq = min(qwq, ds[a][b]);
                }
                tmp = max(tmp, qwq);
            }
            res = min(res, tmp);
        }
        cout << res << '\n';
        for (int i = 1; i <= n; i++) G[i].clear();
    }

    return 0;
}