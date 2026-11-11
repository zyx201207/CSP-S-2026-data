#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (((a[j] & ans) == ans) && ((a[j] >> i) & 1)) {
				cnt++;
			}
		}
		if (cnt < m) {
			continue;
		}
		ans += (1ll << i);
	}
	cout << ans;
	return 0;
}