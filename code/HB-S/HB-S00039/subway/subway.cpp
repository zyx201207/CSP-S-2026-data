#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long

int n, m, k, w[N]; bool vis[N];
ll dis[505][505];
vector< pair<int, ll> > e[N + 500];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%*d%d%d%*d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = (1LL << 62LL) - 1;
    for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) {
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int num, w;
            scanf("%d%d", &num, &w);
            e[num].push_back({i + m, w});
            e[i + m].push_back({num, w});
        }
    } for (int x = 1; x <= m; x++) {
        for (auto i : e[x]) for (auto j : e[x]) if (i != j) {
            int x1 = i.first, x2 = j.first;
            ll w1 = i.second, w2 = j.second;
            dis[x1 - m][x2 - m] = min(dis[x1 - m][x2 - m], w1 + w2);
        }
    } for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] < (1LL << 62LL) - 1 && dis[k][j] < (1LL << 62LL) - 1)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (k--) {
        int u, v; scanf("%d%d", &u, &v);
        ll ans = (1LL << 62LL) - 1;
        for (auto i : e[u]) for (auto j : e[v]) {
            int st = i.first, ed = j.first;
            ll w1 = i.second, w2 = j.second;
            ans = min(ans, w1 + w2 + dis[st - m][ed - m]);
        } printf("%lld\n", ans + w[u] + w[v]);
    }
    return 0;
}