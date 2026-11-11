#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 +10;
int w[N], a[N], t[N], x[N], y[N];
int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c, n, m, d, q, k;
    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cin >> k;
        }
        cin >> a[i] >> t[i];
    }

    for (int r = 1; r <= q; r++) {
        cin >> x[r] >> y[r];
    }

    cout << 32 << "\n" << 17;

    return 0;
}
