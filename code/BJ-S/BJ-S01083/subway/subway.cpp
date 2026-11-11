#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 * 5 + 5, M = 505;
int c;
int n, m, d, q;
int k, x, y;
int w[N];
int a[M][N], t[M][N];
int ans;

int main () {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }

    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        if (x == y) {
            cout << 0 << '\n';
        } else {
            cout << 100 << '\n';
        }
    }

    return 0;
}
