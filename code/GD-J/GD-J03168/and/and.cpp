#include <cstdint>
#include <iostream>
#include <vector>

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

u32 dig(u32 x, u32 d) {
	return ((x >> d) & 1);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	u32 n, m;
	std::vector<u32> a;
	std::cin >> n >> m;
	a.resize(n);
	for (u32 i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	u32 ans = 0;
	std::vector<u32> v0 = a, v1;
	for (u32 d = 30; d != -1u; --d) {
		u32 cnt = 0;
		for (u32 i = 0; i < v0.size(); ++i) {
			cnt += dig(v0[i], d);
		}
		if (cnt < m) {
			continue;
		}
		ans |= (1u << d);
		for (u32 i = 0; i < v0.size(); ++i) {
			if (dig(v0[i], d)) {
				v1.emplace_back(v0[i]);
			}
		}
		v0 = v1;
		v1.clear();
	}
	std::cout << ans << std::endl;
	return 0;
}
