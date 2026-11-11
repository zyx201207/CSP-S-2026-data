// Created by YoungL
// Date: 10/31/2026
#include <bits/stdc++.h>
//#define ONLINE_JUDGE
#define FILENAME "crystal"

using ll = long long;
constexpr int N = 5e5 + 5;
int n;
ll m;    // m <= 1e18
ll a[N]; // a[i] <= 1e18

inline void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	
	std::sort(a + 1, a + 1 + n);
	int l = 1;
	int r = 0;
	ll req = 0;
	int ans = 0;
	while (r < n) {
		++r;
		// Extend to R;
		ll dif = a[r] - a[r - 1];
		ll siz = r - l;
		req += dif * siz;
		
		// Contract L;
		while (l <= r and req > m) {
			req -= a[r] - a[l];
			++l;
		}
		
		ans = std::max(ans, r - l + 1);
	}
	std::cout << ans << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif

	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	
	solve();

	return 0;
}

