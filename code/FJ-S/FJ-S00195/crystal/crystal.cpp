#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

template <typename T>
using U = std::make_unsigned_t<T>;
using ll = long long;
using i128 = __int128_t;
using u128 = __uint128_t;

constexpr int N = 5e5 + 5;

ll a[N], s[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n; ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	std::partial_sum(a + 1, a + n + 1, s + 1);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if ((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = std::max(ans, i - l + 1);
	}
	cout << ans;
}
