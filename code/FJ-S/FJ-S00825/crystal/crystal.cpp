#include <cstdio>
#include <algorithm>
long long n, m, a[500005], ca[500005], pre[500005], maxn;
bool check(int l, int r) {
	if ((pre[r] - pre[l] - (a[r] - a[l]) * l) <= m) return 1;
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	std::sort(a, a + n);
	ca[0] = a[0];
	for (int i = 1; i < n; ++i) {
		ca[i] = a[i] - a[i - 1];
		pre[i] = pre[i - 1] + ca[i] * i;
	}
	for (int i = 1; i < n; ++i) {
		int l = 0, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		int ans = i - l + 1;
		if (ans > maxn) maxn = ans;
	}
	printf("%lld", maxn);
}
