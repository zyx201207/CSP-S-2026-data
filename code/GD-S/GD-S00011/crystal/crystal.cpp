#include <algorithm>
#include <iostream>
#include <vector>

typedef long long i64;
const int N = 5e5 + 7;
i64 a[N], m;
int n;

inline void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	int l = 1;
	int ans = 0;
	i64 sum = 0;
	for(int r = 1; r <= n; ++r) {
		sum += a[r];
		while(a[r] * (r - l + 1) - sum > m)
			++l, sum -= a[l];
		ans = std::max(ans, r - l + 1);
	}
	std::cout << ans << "\n";
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(0) , std::cin.tie(0), std::cout.tie(0);
	solve();
}
