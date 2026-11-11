#include <bits/stdc++.h>
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, ll>;
const int N = 5e5 + 5;
const int M = 505;
ll w[N], dist[M][M];
int testid, n, m, D, q;
vector<pii> bel[N];
int main() {
    FILE("subway");
    FASTIO;
    cin >> testid >> n >> m >> D >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        int len; cin >> len;
        while (len--) {
            int id; ll tim;
            cin >> id >> tim;
            bel[id].emplace_back(i, tim);
        }
    }
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        for (auto fst : bel[i]) {
            int u1 = fst.first;
            ll tim1 = fst.second;
            for (auto sec : bel[i]) {
                int u2 = sec.first;
                ll tim2 = sec.second;
                if (u1 == u2) continue;
                dist[u1][u2] = min(dist[u1][u2], tim1 + tim2);
            }
        }
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (auto fst : bel[x]) {
            int u = fst.first;
            ll tim1 = fst.second;
            for (auto sec : bel[y]) {
                int v = sec.first;
                ll tim2 = sec.second;
                ans = min(ans, tim1 + tim2 + dist[u][v]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
// AC on 14:59