#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q;
int w[510], k[510], a[510][510], t[510][510], x[510], y[510];

int solve(int cur, int mu) {
    return w[cur] + w[mu] + t[cur][mu] + t[cur][cur] + t[mu][mu];
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < q; i++) {
        int ans = w[x[i]] + t[x[i]][x[i]], cur = w[i];

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int g = cur + 1;
                if (a[j][g] == a[k][g]) {
                    ans += solve(cur, g);
                    cur == g;
                }
                else g++;
            }
            if (cur == y[i]) continue;
        }
        cout << ans << endl;
    }

    return 0;
}
