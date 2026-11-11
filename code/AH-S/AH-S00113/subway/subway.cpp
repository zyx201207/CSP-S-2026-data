#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510, MAXM = 5e5 + 100, MAXQ = 1e5 + 100;
int c, n, m, d, q;
int w[MAXM], k[MAXN], a[MAXN][MAXM], t[MAXN][MAXM];
int x[MAXQ], y[MAXQ];

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> c >> n >> m >> d >> q;

    for (int i=1; i<=m; i++) cin >> w[i];

    for (int i=1; i<=n; i++) {
        cin >> k[i];
        for (int j=1; j<=k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }

    for (int i=1; i<=q; i++) {
        cin >> x[i] >> y[i];
        cout << w[x[i]] + w[y[i]] << "\n";
    }

    return 0;
}
