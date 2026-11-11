#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, x, y, ans;
int w[2005], a[2005][2005], t[2005][2005];
int g[2005][2005];

void dfs(int now, int time) {
    if (time >= ans) return;
    if (now == y) {
        ans = min(ans, time);
        return ;
    }
    for (int i = now; i <= m; i++) {
        if (g[now][i] != 0) {
            dfs(i, time + g[now][i]);
        }
        if (g[now][m - i] != 0) {
            dfs(m - i, time + g[now][m - i]);
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0];
        for (int j = 1; j <= a[i][0]; ++j) cin >> a[i][j] >> t[i][j];
        for (int j = 1; j <= a[i][0]; ++j)
            for (int k = 1; k <= a[i][0]; ++k) {
                if (j != k) g[j][k] = t[i][k] + t[i][j], g[k][j] = t[i][k] + t[i][j];
            }
    }
    while (q--) {
        cin >> x >> y;
        ans = 1e9;
        dfs(x, w[x] + w[y]);
        cout << ans + 2 * t[1][1]<< endl;
    }
    return 0;
}
