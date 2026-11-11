#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int M = 5e5 + 5;
int ww[M];
ll ed[N][N];
int n, m, d, q;
vector<pair<int, int> > e[M];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(ed, 0x3f, sizeof(ed));
    scanf("%*d%d%d%d%d", &n, &m, &d, &q);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &ww[i]);
    for(int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; ++j) {
            int v, t;
            scanf("%d%d", &v, &t);
            e[v].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; ++i)
        ed[i][i] = 0;
    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j < e[i].size(); ++j)
            for(int k = j + 1; k < e[i].size(); ++k) {
                int u = e[i][j].first, v = e[i][k].first;
                ll w = e[i][j].second + e[i][k].second;
                ed[u][v] = min(ed[u][v], w);
                ed[v][u] = min(ed[v][u], w);
            }
    }
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                ed[i][j] = min(ed[i][j], ed[i][k] + ed[k][j]);
    while(q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        ll ans = 1ll << 60;
        for(auto px : e[u])
            for(auto qx : e[v])
                ans = min(ans, px.second + qx.second + ed[px.first][qx.first]);
        printf("%lld\n", ans + ww[u] + ww[v]);
    }
}
