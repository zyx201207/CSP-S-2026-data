#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
namespace pnl{
    typedef long long lnt;
    constexpr lnt N = 500100, M = 600;
    lnt tid, n, m, d, q, ans;
    lnt a[N], dis[M][M];
    vector<pair<lnt, lnt>> edg[N];
    inline int _00() {
        scanf("%lld%lld%lld%lld%lld", &tid, &m, &n, &d, &q);
        for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        for (int i = 1; i <= m; ++i) {
            lnt x;
            scanf("%lld", &x);
            for (int j = 1; j <= x; ++j) {
                lnt y, z;
                scanf("%lld%lld", &y, &z);
                edg[y].push_back({i, z});
            }
        }

        for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) if (i != j) dis[i][j] = 0x3f3f3f3f3f3f3f3f;
        else dis[i][j] = 0;
        for (int i = 1; i <= n; ++i) for (pair<lnt, lnt> j : edg[i]) for (pair<lnt, lnt> k : edg[i]) {
            dis[j.first][k.first] = dis[k.first][j.first] = min(dis[j.first][k.first], j.second + k.second);
        }

        for (int k = 1; k <= m; ++k) for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for (int i = 1; i <= q; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            ans = 0x3f3f3f3f3f3f3f3f;
            for (pair<lnt, lnt> j : edg[x]) for (pair<lnt, lnt> k : edg[y]) ans = min(ans, dis[j.first][k.first] + j.second + k.second);
            printf("%lld\n", ans + a[x] + a[y]);
        }

        return 0;
    }
}

int main() {
    // Audaces fortuna iuvat
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    return pnl::_00();
}