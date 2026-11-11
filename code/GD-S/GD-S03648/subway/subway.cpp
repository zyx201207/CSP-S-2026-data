// O((m+q)*d^2)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int ll

const int N = 505;
const int M = 5e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int id;
int n, m, d, Q;
int tim[M];
// int c[N][N];
int dis[N][N];
// map<int, int> mp[N];
vector<pair<int, int>> a[M];

signed main()
{
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> id >> n >> m >> d >> Q;
    rep(i, 1, m) cin >> tim[i];
    rep(i, 1, n)
    {
        int k, x, y;
        cin >> k;
        rep(j, 1, k)
        {
            cin >> x >> y;
            // mp[i][x] = y;
            a[x].push_back({i, y});
        }
    }
    rep(i, 1, n) rep(j, 1, n) dis[i][j] = INF;
    rep(i, 1, n) dis[i][i] = 0;
    rep(i, 1, m)
    {
        int sz = a[i].size();
        rep(j, 1, sz) rep(k, j + 1, sz)
        {
            int u = a[i][j - 1].first, v = a[i][k - 1].first;
            dis[u][v] = dis[v][u] = min(dis[u][v], a[i][j - 1].second + a[i][k - 1].second);
        }
    }
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    // rep(i, 1, n) rep(j, 1, n) cerr << dis[i][j] << " \n"[j == n];
    while (Q--)
    {
        int x, y, ans = INF;
        cin >> x >> y;
        // if (x == y) ans = 0;
        for (auto u : a[x]) for (auto v : a[y])
            ans = min(ans, dis[u.first][v.first] + u.second + v.second);
        ans += tim[x] + tim[y];
        cout << ans << '\n';
    }
    // cerr << fixed << setprecision(4) << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
