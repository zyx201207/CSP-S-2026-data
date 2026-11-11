#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2e6 + 10;

int x[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) {
		int n, d; cin >> n >> d;
		for (int i = 1; i <= n; ++i) 
			cin >> x[i];
		int tmp = d / (x[2] - x[1]);
		if (tmp < 2) cout << 0 << '\n'; 
		if (tmp >= 2) {
			int ans = 0;
			for (int j = 0; j <= min(tmp, n - tmp); ++j)
				ans += n - tmp - j;
			cout << ans << '\n';
		}
	}
	return 0; 
}
