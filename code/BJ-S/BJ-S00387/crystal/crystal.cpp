#include <iostream>
#include <algorithm>
const int MAXN = 5e5 + 5;
using ll = long long;

int n, ans = -1e9; ll m;
ll a[MAXN];

void solvealli() {
	ll x = 1;
	for (int i = 2; ; i++) {
		ll pre = x;
		x += i;
		if (pre <= m && m < x) {
			std::cout << i << '\n';
			break;
		}
	}
}

int main() {
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	std::cin >> n >> m;
	bool alli = true;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		alli = alli && (a[i] == i);
	}
	if (alli) {
		solvealli();
		return 0;
	}
	std::sort(a + 1, a + n + 1);
	for (int x = 1; x <= n; x++) {
		ll cur = a[x]; int res = 0;
		ll m_ = m;
		for (int i = 1; i <= n; i++)
			if (cur == a[i]) res++;
		for (int i = x - 1; i; i--) {
			ll diff = cur - a[i];
			if (m_ - diff < 0) break;
			m_ -= diff;
			res++;
		}
		ans = std::max(ans, res);
	}
	std::cout << ans << '\n';
	return 0;
}

// i love 3 forever