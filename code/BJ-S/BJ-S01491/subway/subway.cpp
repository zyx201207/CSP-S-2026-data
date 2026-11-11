#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 501, M = 2e4 + 1;
ll c, n, m, d, q, ans, T;
ll w[M], k[N], a[N][M], t[N][M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for (int i = 1, k; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%lld %lld", &a[i][j], &t[i][j]);
            T = t[i][j];
        }
    }
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%lld\n", w[x] + w[y] + (y - x) * T);
    }
    return 0;
}

// Oct31==Dec25?
