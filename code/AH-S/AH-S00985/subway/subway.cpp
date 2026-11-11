#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
const int MAX = 5e5;
int k[500], w[MAX], a[500][MAX], t[500][MAX], x[MAX], y[MAX];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < m; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) cin >> a[i][j] >> t[i][j];
    }
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
    }



    return 0;
}
