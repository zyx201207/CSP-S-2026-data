#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[500001];
long long f[501][501];
vector<pair<int, int>> v[500001];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%*d%d%d%*d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int x, y;
            scanf("%d%d", &x, &y);
            v[x].push_back({i, y});
        }
    }
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < v[i].size(); j++)
            for (int k = 0; k < j; k++) {
                f[v[i][j].first][v[i][k].first] = min(f[v[i][j].first][v[i][k].first], 1LL * v[i][j].second + v[i][k].second);
                f[v[i][k].first][v[i][j].first] = min(f[v[i][k].first][v[i][j].first], 1LL * v[i][j].second + v[i][k].second);
            }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        long long ans = 9e18;
        for (auto i : v[x])
            for (auto j : v[y])
                ans = min(ans, f[i.first][j.first] + i.second + j.second);
        printf("%lld\n", ans + a[x] + a[y]);
    }
}