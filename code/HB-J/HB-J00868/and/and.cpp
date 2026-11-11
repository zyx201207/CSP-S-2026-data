#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], f[200005][200005];
int main() {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        f[i][1] = max(f[i - 1][1], a[i]);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = max(f[i - 1][j - 1] & a[i], f[i - 1][j]);
        }
    }

    cout << f[n][m];

    return 0;
}
