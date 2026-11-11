#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 505, M = 5e5 + 5;
bool b1;
int _, n, m, d, q, w[M], f[N][N], idx[M], to[M][21]; vector <int> v[M]; signed t[M][21];
bool b2;
void ins(int x, int y, int w) { f[x][y] = f[y][x] = min(f[x][y], w); }

signed main() {
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cerr << (&b1 - &b2) / 1024. / 1024 << '\n';
    cin >> _ >> n >> m >> d >> q;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int x; k--; ) cin >> x >> t[x][++idx[x]], v[x].push_back(idx[x]), to[x][idx[x]] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int a : v[i]) for (int b : v[i]) {
            if (a != b) ins(to[i][a], to[i][b], t[i][a] + t[i][b]);
        }
    }
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }
    for (int x, y; q--; ) {
        cin >> x >> y; int res = 1e18;
        for (int a : v[x]) for (int b : v[y]) res = min(res, t[x][a] + f[to[x][a]][to[y][b]] + t[y][b]);
        cout << res + w[x] + w[y] << '\n';
    }
    return 0;
}