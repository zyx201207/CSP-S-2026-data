#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair <int, ll> pii;
const int N = 5e5 + 10; /// change the range
int w[N];
vector <pii> v[N];
ll g[510][510];
signed main()
{
    freopen ("subway.in", "r", stdin); ///write the name
    freopen ("subway.out", "w", stdout); ///write the name
    int c, n, m, d, q; scanf ("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) scanf ("%d", w + i);
    for (int i = 1; i <= n; i++)
    {
        int k; scanf ("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            int a, t; scanf ("%d %d", &a, &t);
            v[a].push_back ({i, t});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) g[i][j] = 1e18;
            else g[i][j] = 0;
    for (int i = 1; i <= m; i++)
        for (pii j : v[i])
            for (pii k : v[i])
            {
                if (j == k) continue;
                g[j.x][k.x] = min (g[j.x][k.x], j.y + k.y);
                g[k.x][j.x] = min (g[k.x][j.x], j.y + k.y);
            }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
    while (q--)
    {
        int x, y; scanf ("%d %d", &x, &y);
        ll ans = w[x] + w[y], res = 2e18;
        for (pii i : v[x])
            for (pii j : v[y])
                res = min (res, g[i.x][j.x] + i.y + j.y);
        printf ("%lld\n", ans + res);
    }
    return 0;
}