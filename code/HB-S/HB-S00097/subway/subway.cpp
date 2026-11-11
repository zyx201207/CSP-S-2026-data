// subway
#include <iostream>
#include <vector>
using namespace std;

#define LL long long
const int M = 5e5 + 500 + 1023;
int c, n, m, d, q;
LL w[M], dis[505][505];
vector<pair<int, LL>> e[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i) scanf("%lld", &w[i]);
    for (int i = 1, k; i <= n; ++i) {
        scanf("%d", &k);
        for (int v, t; k--;) {
            scanf("%d%d", &v, &t);
            e[i].push_back({v + n, t});
            e[v + n].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            dis[i][j] = 1e18;
        dis[i][i] = 0;
    }
    for (int u = 1; u <= n; ++u) {
        for (auto it : e[u]) {
            int i = it.first;
            LL w1 = it.second;
            for (auto nxt : e[i]) {
                int v = nxt.first;
                LL w2 = nxt.second;
                dis[u][v] = min(dis[u][v], w1 + w2);
            }
        }
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int x, y; q--;) {
        scanf("%d%d", &x, &y);
        LL ans = 1e18;
        for (auto ex : e[n + x]) {
            int u = ex.first;
            LL w1 = ex.second;
            for (auto ey : e[n + y]) {
                int v = ey.first;
                LL w2 = ey.second;
                ans = min(ans, w1 + dis[u][v] + w2);
            }
        }
        printf("%lld\n", w[x] + ans + w[y]);
    }
    return 0;
}
