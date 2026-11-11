#include <bits/stdc++.h>

using namespace std;

int n, ans;
long long m, a[500100], add[500100], cnt[500100], lnx[500100];

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);	
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		add[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] = cnt[i - 1] + add[i];
	}
	for (int i = n; i >= 1; i--) {
		lnx[i] = lnx[i + 1] + cnt[i];
	}
	for (int i = 1; i <= n; i++) {
		int L = 0, R = i + 1;
		while (L + 1 != R) {
			int M = (L + R) / 2;
			long long LNX = 1LL * (i - M + 1) * cnt[i] - lnx[M] + lnx[i + 1];
			if (LNX <= m) {
				R = M;
			} else {
				L = M;
			}
		}
		ans = max (ans, i - L);
	}
	printf ("%d", ans);
	return 0;
}
