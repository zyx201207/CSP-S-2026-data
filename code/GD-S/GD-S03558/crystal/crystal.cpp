#include <stdio.h>
#include <algorithm>
long long a[500005], pre[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n; 
	long long m; scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = a[i] + pre[i - 1];
	int l = 1, ans = 1;
	for (int i = 1; i <= n; i++) {
		long long cost;
		int len = i - l + 1;
		while (l <= n && (cost = len * a[i] - (pre[i] - pre[l - 1])) > m) {
			l++;
			len = i - l + 1;
		}
		if (cost <= m) {
			if (len > ans) ans = len;
		}
	}
	printf("%d", ans);
	return 0;
} 
