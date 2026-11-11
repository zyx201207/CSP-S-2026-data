#include <bits/stdc++.h>
#define fi first
#define endl '\n'
#define se second
#define il inline
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10;
const int M = 5e2 + 10;
int n, m, q, a[N];
ll f[M][M];
vector<pair<int, ll>> G[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(f, 0x3f, sizeof f);
    int Cas;
    cin >> Cas >> n >> m >> Cas >> q;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1, k; i <= n; i++)
    {
        f[i][i] = 0;
        cin >> k;
        while (k--)
        {
            int x, y;
            cin >> x >> y;
            for (auto [a, b] : G[x])
                f[i][a] = f[a][i] = min(f[a][i], b + y);
            G[x].pb({i, y});
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--)
    {
        int x, y;
        ll ans = INF;
        cin >> x >> y;
        for (auto [a, b] : G[x])
            for (auto [c, d] : G[y])
                    ans = min(ans, b + d + f[a][c]);
        cout << a[x] + a[y] + ans << endl;
    }
    return 0;
}