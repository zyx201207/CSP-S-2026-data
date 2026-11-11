#include <bits/stdc++.h>

using namespace std;

int t, h, n, ans, lnx, d[2000100], e[2000100];
long long m, a[2000100], b[2000100], c[2000100];
bool nx, ln;

int LNX (int x, int y, int r) {
	if (x == y) {
		if (r == lnx) {
			if (nx == true) {
				ln = false;
			} else {
				nx = true; 
				ln = true;
			}
		} else {
			lnx = min (lnx, r);
			ln = false;
			nx = false;
		}
		return 0;
	}
	for (int i = x + 1; i <= min (e[x], y); i++) {
		int o = LNX (i, y, r + 1);
	}
	return 0;
}

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);	
	scanf ("%d%d", &h, &t);
	while (t--) {
		scanf ("%d%lld", &n, &m);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%lld", &a[i]);
		}
		for (int i = 1; i < n; i++) {
			b[i + 1] = a[i + 1] - a[i];
		}
		for (int i = 1; i < n; i++) {
			c[i + 1] = c[i] + b[i + 1];
		}
		for (int i = 2; i <= n; i++) {
			int L = 0, R = i;
			while (L + 1 != R) {
				int M = (L + R) / 2;
				if (c[i] - c[M] <= m) {
					L = M;
				} else {
					R = M;
				}
			}
			d[i] = L;
		}
		for (int i = 1; i <= n; i++) {
			int L = i, R = n + 1;
			while (L + 1 != R) {
				int M = (L + R) / 2;
				if (c[M] - c[i] <= m) {
					L = M;
				} else {
					R = M;
				}
			}
			e[i] = L;
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				lnx = n + 1;
				nx = false, ln = false;
				int l = LNX (i, j, 0);
				if (ln) {
					ans++;
				}
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
