#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

namespace code {
	const int N = 5e5 + 5;
	int n, m, s[N], a[N];
	
	void niam() {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) 
			cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++)
			s[i] = s[i - 1] + a[i];
		int ans = 0;
		for(int l = 1, r = 1; r <= n; r++) {
			while(l < r && a[r] * (r - l + 1) - (s[r] - s[l - 1]) > m)
				l++;	
			ans = max(ans, r - l + 1);
		}
		cout << ans;
	}
}

signed main() {
#ifndef _NO_FREOPEN_
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	code::niam();
	
	return 0;
}

/*
30min
*/
