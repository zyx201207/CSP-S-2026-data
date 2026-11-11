#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510, M = 5e5 + 10;

int c, n, m, d, q; ll w[M];
vector<pair<int, int> > e[N];
vector<pair<int, int> > p[M];

ll dis[N][N];
bool vis[M]; ll T[M];

int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i ++ ) cin >> w[i];

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ ) if (i != j) dis[i][j] = 1e18;

    for (int i = 1; i <= n; i ++ ) {
        int k; cin >> k;
        for (int j = 1, a, t; j <= k; j ++ )
            cin >> a >> t, e[i].push_back({a, t}), p[a].push_back({i, t});
    }

    for (int i = 1; i <= n; i ++ ) {
        for (auto j : e[i])
            vis[j.first] = 1, T[j.first] = j.second;
        for (int j = 1; j < i; j ++ ) {
            for (auto k : e[j])
                if (vis[k.first]) dis[i][j] = dis[j][i] = min(dis[i][j], T[k.first] + k.second);
        }
        for (auto j : e[i]) vis[j.first] = 0;
    }

    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    while (q -- ) {
        int x, y; cin >> x >> y;
        ll ans = 1e18;
        for (auto i : p[x])
            for (auto j : p[y])
                ans = min(dis[i.first][j.first] + i.second + j.second, ans);
        cout << ans + w[x] + w[y] << '\n';
    }

    return 0;
}