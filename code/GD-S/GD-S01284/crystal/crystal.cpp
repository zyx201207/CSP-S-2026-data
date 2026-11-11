#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	 freopen("crystal.in", "r", stdin);
	 freopen("crystal.out", "w", stdout);
	u32 n;
	u64 m;
	std::vector<i64> a, pre;
	std::cin >> n >> m;
	a.resize(n), pre.assign(n, 0);
	for (u32 i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	u32 ans = 0;
	for (u32 i = 0; i < n; ++i) {
		pre[i] = (i == 0 ? a[i] : (pre[i - 1] + a[i]));
		u32 l = 0, r = i;
		while (l < r) {
			u32 mid = (l + r) >> 1;
			i64 s = pre[i] - (mid == 0 ? 0 : pre[mid - 1]);
			if (a[i] * static_cast<i64>(i - mid + 1) - s <= static_cast<i64>(m)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = std::max(ans, i - l + 1);
	}
	std::cout << ans << std::endl;
	return 0;
}
