#include <stdio.h>
#include <stdlib.h>
#define ll long long
int n, ans;
ll m, a[500010], sum[500010];
int cmp(const void *a, const void *b) { return *(ll*)a - *(ll*)b > 0 ? 1 : -1; }
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	qsort(a + 1, n, sizeof a[0], cmp);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i;
		while (l + 1 < r) {
			int mid = l + r >> 1;
			if ((sum[i] - sum[mid - 1] - 1ll * (i - mid + 1) * a[i]) + m >= 0) r = mid;
			else l = mid;
		}
		if (i - r + 1 > ans) ans = i - r + 1;
	}
	printf("%d", ans);
	return 0;
}
