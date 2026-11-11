#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;
const ll INF = 1ll << 60;

const int N = 503;
const int M = 5e5 + 3;

ll d[N][N];

pair<int, int> p[M][21];

int l[M], w[M];

int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(d, 127, sizeof(d));
    int c, n, m, D, q;
    scanf ("%d%d%d%d%d", &c, &n, &m, &D, &q);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 1; i <= m; i++) scanf ("%d", &w[i]);
    for (int ln = 1; ln <= n; ln++) {
        int k;
        scanf ("%d", &k);
        for (int i = 1; i <= k; i++) {
            int a, t;
            scanf ("%d%d", &a, &t);
            for (int j = 1; j <= l[a]; j++) if (d[p[a][j].first][ln] > t + p[a][j].second)
                d[p[a][j].first][ln] = d[ln][p[a][j].first] = t + p[a][j].second;
            p[a][++l[a]] = make_pair(ln, t);
        }
    }
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (d[i][k] < INF && d[k][j] < INF)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (; q--; ) {
        int x, y;
        scanf ("%d%d", &x, &y);
        ll ans = INF;
        for (int i = 1; i <= l[x]; i++) for (int j = 1; j <= l[y]; j++)
            ans = min(ans, d[p[x][i].first][p[y][j].first] + w[x] + p[x][i].second + w[y] + p[y][j].second);
        printf("%lld\n", ans);
    }
}