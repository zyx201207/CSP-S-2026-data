#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

namespace code {
	const int N = 5e5 + 5;
	int n, d, a[N], dp1[N], dp2[N];
	
	void solve() {
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 0;
		for(int st = 1; st <= n; st++) {
			for(int i = 1; i <= n; i++)
				dp1[i] = dp2[i] = 1e9;
			dp1[st] = 0; dp2[st] = 1;
			for(int i = st; i <= n; i++) {
				for(int j = i + 1; a[j] - a[i] <= d && j <= n; j++) {
					if(dp1[j] > dp1[i] + 1) {
//						cout << ">> " << i << ' ' << j << '\n';
						dp1[j] = dp1[i] + 1;
						dp2[j] = dp2[i];
					}
					else if(dp1[i] + 1 == dp1[j])
						dp2[j] += dp2[i];
				}
			}
//			for(int i = 1; i <= n; i++)
//				cout << dp2[i] << ' ';
//			cout << '\n';
			for(int i = st + 1; i <= n; i++)
				if(dp2[i] == 2)
					ans++;
		}
		cout << ans << '\n';
	}
	
	void niam() {
		int c, t;
		cin >> c >> t;
		while(t--)
			solve();
	}
}

signed main() {
#ifndef _NO_FREOPEN_
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	code::niam();
	
	return 0;
}
