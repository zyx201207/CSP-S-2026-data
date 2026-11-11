#include <cstdio>
int n, a[200005], i, j;
long long ans;
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d\n%c", &a[i], &c[i]);
	i = 1, j = n;
	while (i < j) {
		if (c[i] == c[j]) {
			if (a[i] > a[j]) a[i] -= a[j], --j;
			else if (a[j] > a[i]) a[j] -= a[i], ++i;
			else ++i, --j;
		} else {
			if (a[i] > a[j]) a[i] -= a[j], ans += a[j], --j;
			else if (a[j] > a[i]) a[j] -= a[i], ans += a[i], ++i;
			else ans += a[i], ++i, --j;
		}
	}
	printf("%lld", ans);
	return 0;
}
