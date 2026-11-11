#include <stdio.h>
#include <algorithm>
#define max(a, b) (((a) > (b)) ? (a) : (b))
typedef long long int llong;
int n;
llong m, a[500005], diff[500005];
int main (void) {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d %lld", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf ("%lld", &a[i]);
	std::sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; ++i)	diff[i] = diff[i - 1] + (a[i] - a[i - 1]) * ((llong)i - 1LL);
	int ans = 1;
	for (int L = 1; L < n; ++L) {
		int l = L + 1, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			llong add = diff[mid] - diff[L] - (a[mid] - a[L]) * ((llong)L - 1LL);
			if (add <= m)	l = mid + 1;
			else	r = mid - 1;
		}
		if (diff[r] - diff[L] - (a[r] - a[L]) * ((llong)L - 1LL) <= m)	ans = max (ans, r - L + 1);
	}
	printf ("%d\n", ans);
	return 0;
}
