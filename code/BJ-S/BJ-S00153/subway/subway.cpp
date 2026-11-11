#include <bits/stdc++.h>
using namespace std;
long long c, n, k, m, d, q, x, y, w[1000002], t[1002][1002], a[1002][1002];
vector<pair<long long, long long>> vec;
vector<pair<long long, long long>> vec1;
int main() {
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
        vec.clear();
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= k; l++) {
                if (a[i][j] == y) {
                    vec.push_back({i, j});
                } if (a[i][j] == x) {
                    vec1.push_back({i, j});
                }
            }
        }
        long long res = w[x] + w[y] + t[1][1] + t[1][2];
        cout << res << '\n';
    }
    return 0;
}
