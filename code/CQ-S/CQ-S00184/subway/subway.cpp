#include <bits/stdc++.h>

using namespace std;

int o, n, m, d, q;
long long ans, a[2000100], b[2000100], c[2000100];
bool nx, ln;

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);	
	scanf ("%d%d%d%d%d", &o, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf ("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%lld%lld", &b[i], &c[i]);
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		int x, y;
		scanf ("%d%d", &x, &y);
		for (int j = 1; j <= n; j++) {
			if (m / x == i || m % y == i) {
				ans += a[i];
			}
			if (n / y == i || n % y == i) {
				ans += b[i];
			}
			if (n / i == 15 || n % i == 7) {
				ans += c[i];
			}
		}
		printf ("%lld\n", ans); 
	}
	return 0;
}
