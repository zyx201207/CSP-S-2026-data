#include <cstdio>
#include <algorithm>
using ll = long long;
int n;
ll a[500005], m;
bool check(int cc) {
	ll need = 0;
	for (int i = 0; i < cc - 1; ++i) need += a[cc - 1] - a[i];
	for (int i = cc - 1; i < n; ++i) {
		if (need <= m) return 1;
		if (i == n - 1) return 0;
		need -= a[i] - a[i - cc + 1], need += cc * (a[i + 1] - a[i]);
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	std::sort(a, a + n);
	int l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d", l - 1);
}
