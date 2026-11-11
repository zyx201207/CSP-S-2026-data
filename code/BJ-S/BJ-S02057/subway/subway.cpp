#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 5, M = 505, D = 21;
int Case, n, m, d, q, id[N][D], t[N][D], len[N], w[N];
ll f[M][M];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    cin >> Case >> m >> n >> d >> q;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        int k; cin >> k;
        while (k--) {
            int x, y; cin >> x >> y;
            ++len[x];
            id[x][len[x]] = i;
            t[x][len[x]] = y;
        }
    }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
            f[i][j] = 1e18;
    for (int i = 1; i <= m; ++i) f[i][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= len[i]; ++j) {
            for (int k = j + 1; k <= len[i]; ++k) {
                int x = id[i][j], y = id[i][k];
                ll tmp = t[i][j] + t[i][k];
                f[x][y] = min(f[x][y], tmp);
                f[y][x] = min(f[y][x], tmp);
            }
        }
    }
    for (int k = 1; k <= m; ++k)
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--) {
        int x, y; cin >> x >> y;
        if (x == y) {
            cout << "0\n";
            continue ;
        }
        ll ans = 1e18;
        for (int i = 1; i <= len[x]; ++i)
            for (int j = 1; j <= len[y]; ++j) {
                int p = id[x][i], q = id[y][j];
                ll tmp = t[x][i] + t[y][j];
                tmp += f[p][q];
                ans = min(ans, tmp);
            }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
    return 0;
}
