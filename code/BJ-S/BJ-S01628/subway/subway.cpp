#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
constexpr int N = 500005, M = 505;
inline void upd(ll &x, ll y) {
    x = min(x, y);
}
int n, m, d, q;
ll w[N];
vector<pair<int, int> > adj[N];
ll dis[M][M];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int C;
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x, y;
            cin >> x >> y;
            adj[x].emplace_back(i, y);
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (pair<int, int> x : adj[i])
            for (pair<int, int> y : adj[i])
                upd(dis[x.first][y.first], 0ll + x.second + y.second);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                upd(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll res = 0x3f3f3f3f3f3f3f3f;
        for (pair<int, int> u : adj[x])
            for (pair<int, int> v : adj[y])
                upd(res, dis[u.first][v.first] + u.second + v.second);
        cout << res + w[x] + w[y] << '\n';
    }
    return 0;
}