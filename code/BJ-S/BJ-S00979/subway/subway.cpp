#include <bits/stdc++.h>
using namespace std;
// #define PII pair<int, int>
// #define pb emplace_back
// #define fi first
// #define se second
constexpr int N = 505, M = 500005;
int c, n, m, q, w[M], te[M][2];
vector<int> t[M];
long long g[605][605];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%*d%d", &c, &n, &m, &q);
    for (int i = 1; i <= m; ++i) scanf("%d", w+i);
    if (c >= 1 && c <= 8) {
        memset(g, 0x3f, sizeof(g));
        for (int i = 1; i <= n+m; ++i) g[i][i] = 0;
        for (int i = 1; i <= n; ++i) {
            int k; scanf("%d", &k);
            while (k--) {
                int a, t;
                scanf("%d%d", &a, &t);
                g[i][a+n] = g[a+n][i] = min(g[i][a+n], 1ll*t);
                // g[i].pb(a+n, t);
                // g[a+n].pb(i, t);
            }
        }
        for (int k = 1; k <= n+m; ++k)
            for (int i = 1; i <= n+m; ++i)
                for (int j = 1; j <= n+m; ++j)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            printf("%lld\n", w[x]+g[x+n][y+n]+w[y]);
        }
    } else if (c >= 9 && c <= 11) {
        memset(g, 0x3f, sizeof(g));
        for (int i = 1; i <= m; ++i) g[i][i] = 0;
        // puts("HELLO");
        for (int i = 1; i <= n; ++i) {
            int k; scanf("%d", &k);
            if (k == 2) {
                int a1, t1, a2, t2;
                scanf("%d%d%d%d", &a1, &t1, &a2, &t2);
                // a1 <--t1+t2--> a2
                // printf("%d <==%d==> %d\n", a1, t1+t2, a2);
                g[a1][a2] = g[a2][a1] = min(g[a1][a2], 1ll*t1+t2);
            }
        }
        for (int k = 1; k <= m; ++k)
            for (int i = 1; i <= m; ++i)
                for (int j = 1; j <= m; ++j)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            printf("%lld\n", w[x]+g[x][y]+w[y]);
        }
    } else if (c >= 12 && c <= 19) {
        int cost;
        for (int i = 1; i <= n; ++i) {
            int k; scanf("%d", &k);
            while (k--) {
                int a; scanf("%d%d", &a, &cost);
                t[a].push_back(i);
            }
        }
        memset(g, 0x3f, sizeof(g));
        for (int i = 1; i <= n; ++i) g[i][i] = 0;
        for (int i = 1; i <= m; ++i) {
            int sz = t[i].size();
            for (int a = 0; a < sz; ++a)
                for (int b = 0; b < sz; ++b) if (a != b) {
                    g[t[i][a]][t[i][b]] = g[t[i][b]][t[i][a]] = 1;
                }
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            long long ans = w[x] + w[y], as = 9e18;
            for (int a : t[x])
                for (int b : t[y])
                    as = min(as, g[a][b]);
            printf("%lld\n", ans+2*(as+1)*cost);
        }
    } else if (c >= 20 && c <= 21) {
        for (int i = 1; i <= n; ++i) {
            int k; scanf("%d", &k);
            while (k--) {
                int a, c; scanf("%d%d", &a, &c);
                te[a][i-1] = c;
            }
        }
        long long best = 9e18;
        for (int i = 1; i <= m; ++i)
            if (te[i][0] && te[i][1])
                best = min(best, 1ll*te[i][0] + te[i][1]);
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            long long ans = w[x] + w[y], mn = 9e18;
            if (te[x][0] && te[y][0]) mn = min(mn, 1ll*te[x][0] + te[y][0]);
            if (te[x][1] && te[y][1]) mn = min(mn, 1ll*te[x][1] + te[y][1]);
            if (te[x][0] && te[y][1]) mn = min(mn, 1ll*te[x][0] + best + te[y][1]);
            if (te[x][1] && te[y][0]) mn = min(mn, 1ll*te[x][1] + best + te[y][0]);
            // if (te[x][0] && te[x][1] && te[y][0] && te[y][1]) printf("%lld\n", ans + min(te[x][0] + te[y][0], te[x][1] + te[y][1]));
            // else if (te[x][0] && te[y][0]) printf("%lld\n", ans + te[x][0] + te[y][0]);
            // else if (te[x][1] && te[y][1]) printf("%lld\n", ans + te[x][1] + te[y][1]);
            // else if (te[x][0]) printf("%lld\n", ans + te[x][0] + best + te[y][1]);
            // else if (te[x][1]) printf("%lld\n", ans + te[x][1] + best + te[y][0]);
            printf("%lld\n", ans + mn);
        }
    }
    return 0;
}