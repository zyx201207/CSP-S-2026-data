#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> m >> d >> q;
    vector<int> w(m), k(n), x(q), y(q);
    vector<vector<int>> a(n), t(n);
    for (int i = 0; i < m; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        a[i] = vector<int>(k[i]);
        t[i] = vector<int>(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int r = 0; r < q; r++) {
        cin >> x[r] >> y[r];
    }

    
}