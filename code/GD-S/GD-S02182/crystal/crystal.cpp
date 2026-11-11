#include <algorithm>
#include <iostream>
int n, ans = 1;
long long m, a[500005];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a, a + n);
	for (int i = 1, l = 0; i < n; ++i) {
		m -= (a[i] - a[i - 1]) * (i - l);
		while (m < 0) {
			m += a[i] - a[l];
			++l;
		}
		if (i - l + 1 > ans) ans = i - l + 1;
	}
	std::cout << ans;
}
