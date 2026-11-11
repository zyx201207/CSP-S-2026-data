#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace Code {
	constexpr int N = 5e5 + 5;

	int n, m;
	int a[N];

	int ans = 1;
	int l = 1, r = 1, c = 0;

	inline void update_r() {
		c += (r - l + 1) * (a[r + 1] - a[r]);
		++ r;
	}

	inline void update_l() {
		c -= a[r] - a[l];
		++ l;
	}

	void main() {
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		
		sort(a + 1, a + 1 + n);

		if (n >= 2) {
			do {
				update_r();
				while (c > m) update_l();
				ans = max(ans, r - l + 1);
			} while (r < n);
		}

		cout << ans << '\n';
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Code::main();

	return 0;
}