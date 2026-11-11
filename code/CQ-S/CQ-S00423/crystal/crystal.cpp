#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500001], b[500001];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    int p = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        while (p <= i && (i - p + 1) * a[i] - (b[i] - b[p - 1]) > m)
            p++;
        ans = max(ans, i - p + 1);
    }
    printf("%d", ans);
}