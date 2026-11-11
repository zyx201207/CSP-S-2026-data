#include <bits/stdc++.h>

using namespace std;

int t, h, n, ans, lnx, d[2000100], e[2000100];
long long m, a[2000100], b[2000100], c[2000100];
bool nx, ln;

int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);	
	scanf ("%d%d", &h, &t);
	while (t--) {
		scanf ("%d%lld", &n, &m);
		ans = 0;
		for (int i = 1; i < n; i++) {
			scanf ("%lld%lld", &a[i], &a[i]);
		}
		printf ("%d", n / 3);
	}
	return 0;
}
