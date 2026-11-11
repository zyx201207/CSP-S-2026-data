// We're not gonna argue whether JR is a subway system
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int caseid, n, m, d, qq;
vector<pair<int, ll> > lines[MAXN];
ll dis[510][510];
ll kuchi[MAXN];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> caseid >> n >> m >> d >> qq;
    for (int i = 1; i <= m; i++) { // notice that m should be there
        cin >> kuchi[i];
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        int k;
        cin >> k;
        while (k--) {
            int x; ll dd;
            cin >> x >> dd;
            lines[x].push_back({i, dd});
        }
    }
    for (int i = 1; i <= m; i++) {
        int k = lines[i].size();
        for (int x = 0; x < k; x++) for (int y = x + 1; y < k; y++) {
            int u = lines[i][x].first, v = lines[i][y].first;
            ll di = lines[i][x].second + lines[i][y].second;
            dis[u][v] = min(dis[u][v], di);
            dis[v][u] = min(dis[v][u], di);
        }
    }
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    while (qq--) {
        int x, y;
        cin >> x >> y;
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for (auto [u, d1]: lines[x]) for (auto [v, d2]: lines[y]) {
            ans = min(ans, dis[u][v] + d1 + d2);
        }
        ans += kuchi[x] + kuchi[y];
        cout << ans << "\n";
    }
    // cerr << "Time used: " << clock() << "\n";
    return 0;
}