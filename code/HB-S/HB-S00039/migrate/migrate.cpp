#include <bits/stdc++.h>
using namespace std;
#define N 2000006
#define ll long long

int T, n;
ll a[N], d;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%*d%d", &T);
    while (T--) {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        long long dd = a[2] - a[1];
        long long cnt = d / dd;
        if (cnt == 0 || cnt == 1) puts("0");
        else printf("%lld\n", max(n - (cnt << 1) + 1, 0LL));
    }
    return 0;
}