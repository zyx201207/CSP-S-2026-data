#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], m, s[N];
int n, ans;
int f(long long k) {
	long long en = 0;
	int x = lower_bound(a + 1, a + 1 + n, k) - a, t = 0;
	for (x; x > 0 && en <= m; x--) {
		en += a[x];
		if (en <= m) t++;
	}
	ans = max(ans, t);
	return t;
}
int find(int x) {
	int l = 0, r = x;
	while (l < r) {
		int mid = (l + r) >> 1;
		if ((a[x] * (x - mid) - s[x] + s[mid]) > m) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		ans = max(ans, (i - find(i)));
	}
	printf("%d", ans);
	return 0;
}
