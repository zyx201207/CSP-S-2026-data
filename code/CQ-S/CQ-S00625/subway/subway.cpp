#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
const int M = 5e5 + 5;
const int D = 22;
int n, m, d, q, w[M], len[M];
pair<int, int> buf[M][D];
LL dis[N][N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
        cin >> w[i];
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        while (k--) {
            int id, tim;
            cin >> id >> tim;
            buf[id][++len[id]] = { i,tim };
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1;i <= n;i++)
        dis[i][i] = 0;
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= len[i];j++) {
            int u = buf[i][j].first;
            int tu = buf[i][j].second;
            for (int k = j + 1;k <= len[i];k++) {
                int v = buf[i][k].first;
                int tv = buf[i][k].second;
                dis[u][v] = min(dis[u][v], 1ll * (tu + tv));
            }
        }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            dis[i][j] = min(dis[i][j], dis[j][i]);
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        LL ans = LLONG_MAX;
        for (int i = 1;i <= len[x];i++)
            for (int j = 1;j <= len[y];j++)
                ans = min(ans, dis[buf[x][i].first][buf[y][j].first] + buf[x][i].second + buf[y][j].second);
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}