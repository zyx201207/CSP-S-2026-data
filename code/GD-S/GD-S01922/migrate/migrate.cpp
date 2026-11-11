#include <bits/stdc++.h>
using namespace std;
int con, test;
int n;
long long d, a[2001000];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &con, &test);
	for (; test--; ) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		long long t = a[2] - a[1], m;
		m = d / t;
		long long ans = 0;
		for (int i = m + 1; i <= n && i <= 2 * m - 1; i++) {
			if (i % m == 0)
				continue;
			ans += (n - i);
		}
		printf("%lld\n", ans);
	}
    return 0;
}
