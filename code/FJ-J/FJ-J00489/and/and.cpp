#include <bits/stdc++.h>
using namespace std;
long long a[500000], n, m, b[500000], l, z[500000], p, u = INT_MAX;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	//freopen("and\\and5.in", "r", stdin);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int o = 29; o >= 0; o--) {
		memset(b, 0, sizeof(b));
		l = 0;
		for (int i = 1; i <= n; i++) if ((a[i] >> o) & 1) l++, b[l] = a[i];
		if (l >= m) {
			for (int i = 1; i <= l; i++) z[i] = b[i];
			p = l;
			for (int i = 1; i <= l; i++) a[i] = b[i];
			n = l;
			l = 0;
		}
	}
	for (int i = 1; i <= p; i++) {
		u &= z[i];
	}
	printf("%lld\n", u);
	return 0;
}
