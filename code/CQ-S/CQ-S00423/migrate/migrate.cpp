#include <bits/stdc++.h>
using namespace std;

int T, n;
long long m, a[2000001], f[2000001], g[2000001];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%*d%d", &T);
    while (T--) {
        scanf("%d%lld", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        if (n <= 300) {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                f[i] = g[i] = 1;
                for (int j = i + 1; j <= n; j++) {
                    f[j] = 0;
                    g[j] = 1e9;
                    for (int k = j; k >= i && a[j] - a[k] <= m; k--)
                        if (g[k] + 1 < g[j]) {
                            f[j] = f[k];
                            g[j] = g[k] + 1;
                        } else if (g[k] + 1 == g[j])
                            f[j] += f[k];
                    if (f[j] == 2) {
                        ans++;
                        // printf("%d %d\n", i, j);
                    }
                }
            }
            printf("%d\n", ans);
            continue;
        }
        f[1] = 0;
        for (int i = 2; i < n; i++) {
            if (a[i] - a[i - 1] > m)
                f[i] = 0;
            else if (i > 2 && a[i] - a[i - 2] <= m)
                f[i] = lower_bound(a + 1, a + n + 1, a[i + 1] - m) - lower_bound(a + 1, a + n + 1, a[i] - m);
            else if (a[i + 1] - a[i - 1] <= m)
                f[i] = 0;
            else
                f[i] = f[i - 1] + 1;
        }
        g[n] = 0;
        for (int i = n - 1; i > 1; i--) {
            if (a[i + 1] - a[i] > m)
                g[i] = 0;
            else if (i < n - 1 && a[i + 2] - a[i] <= m)
                g[i] = upper_bound(a + 1, a + n + 1, a[i] + m) - upper_bound(a + 1, a + n + 1, a[i - 1] + m);
            else if (a[i + 1] - a[i - 1] <= m)
                g[i] = 0;
            else
                g[i] = g[i + 1] + 1;
        }
        long long ans = 0;
        for (int i = 2; i + 1 < n; i++) {
            int l1 = lower_bound(a + 1, a + n + 1, a[i + 1] - m) - a, r1 = lower_bound(a + 1, a + n + 1, a[i + 2] - m) - a - 1;
            int l2 = upper_bound(a + 1, a + n + 1, a[i - 1] + m) - a, r2 = upper_bound(a + 1, a + n + 1, a[i] + m) - a - 1;
            r1 = min(i - 1, r1), l2 = max(i + 2, l2);
            if (l1 > r1 || l2 > r2)
                continue;
            int t1 = r1 - l1 + 1, t2 = r2 - l2 + 1;
            if (a[i] - a[l1 - 1] > m)
                t1 += f[l1];
            if (a[r2 + 1] - a[i + 1] > m)
                t2 += g[r2];
            ans += 1LL * t1 * t2;
        }
        printf("%lld\n", ans);
    }
}