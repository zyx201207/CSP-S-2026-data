#include <bits/stdc++.h>

using namespace std;

int T, n, m, d, q;
long long a[505][505];
long long b[500005];
pair<int, long long> c[500005][25];
int e[500005];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> T >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> b[i];
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++) {
            int x;
            long long y;
            cin >> x >> y;
            c[x][++ e[x]] = make_pair(i, y);
        }
    }
    memset(a, 0x3f, sizeof(a));
    for (int i = 1; i <= m; i ++) {
        for (int jj = 1; jj <= e[i]; jj ++) {
            for (int kk = 1; kk < jj; kk ++) {
                auto j = c[i][jj];
                auto k = c[i][kk];
                if (j.first == k.first) continue;
                a[j.first][k.first] = min(a[j.first][k.first], j.second + k.second);
                a[k.first][j.first] = min(a[k.first][j.first], j.second + k.second);
            }
        }
    }
    for (int i = 1; i <= n; i ++) a[i][i] = 0;
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= n; j ++) cout << a[i][j] << " ";
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int k = 1; k <= n; k ++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    // cout << endl;
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= n; j ++) cout << a[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 1; i <= q; i ++) {
        int x, y;
        cin >> x >> y;
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int jj = 1; jj <= e[x]; jj ++) {
            for (int kk = 1; kk <= e[y]; kk ++) {
                auto j = c[x][jj];
                auto k = c[y][kk];
                // cout << x << "->l" << j.first << "->l" << k.first << "->" << y << " " << j.second << " " << a[j.first][k.first] << " " << k.second << endl;
                ans = min(ans, a[j.first][k.first] + j.second + k.second);
            }
        }
        cout << ans + b[x] + b[y] << "\n";
    }
    return 0;
}