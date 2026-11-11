#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+4;
ll c, n, m, d, q, k, a[N], t[N], w[N], x, y, f[N][N];
int main() {
    // in
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[j] >> t[j];
            for (int l = 1; l < j; l++) {
                f[a[l]][a[j]] = f[a[j]][a[l]] = min({f[a[l]][a[j]], f[a[j]][a[l]], t[j]+t[l]});
            }
            f[a[j]][a[j]] = 0;
        }
    }
    // Floyd
    for (int l = 1; l <= m; l++) {
        for (int i = 1; i <= m; i++) {
            for (int j = i+1; j <= m; j++) {
                f[i][j] = min(f[i][j], f[i][l]+f[l][j]);
                f[j][i] = min(f[j][i], f[j][l]+f[l][i]);
            }
        }
    }
    // out
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        cout << (f[x][y]+w[x]+w[y]) << '\n';
    }
    return 0;
}
