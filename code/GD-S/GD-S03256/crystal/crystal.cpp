#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

template<typename T>
inline T Max(const T& a, const T& b) { return a > b ? a : b; }

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	std::sort(a.begin() + 1, a.end());
	
	int l = 1, r = 1, sum = a[1], ans = 0;
	while (l <= n && r <= n) {
		if ((r - l + 1) * a[r] - sum <= m) {
			ans = Max(ans, r - l + 1);
			++r;
			sum += a[r];
		} else {
			sum -= a[l];
			++l;
		}
	}
	std::cout << ans << '\n';
	
	std::cout << std::flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
