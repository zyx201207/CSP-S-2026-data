#include <cstdio>
int n, m, a[200005], out[200005], ans, flag, num;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n ,&m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 30; i >= 0; --i) {
		int num = 0;
		for (int j = 0; j < n; ++j)
			if (!out[j] && (a[j] >> i & 1)) ++num;
		if (num < m) continue;
		for (int j = 0; j < n; ++j)
			if (!(a[j] >> i & 1)) out[j] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (out[i]) continue;
		if (!flag) ans = a[i], flag = 1;
		else ans &= a[i];
		++num;
		if (num == m) break;
	}
	printf("%d", ans);
	return 0;
}
