#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500510];
int p[500010];
int getsum(int l, int r) {
	return p[r] - p[l-1];
}
int32_t main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i-1] + a[i];
	}
	int ans = 0;
	int l = n, r = n;
	while(l >= 1) {
		while((r - l + 1) * a[r] - getsum(l, r) <= m) {
			l--;
			if (l <= 0) {
				cout << max(r, ans) << '\n';
				return 0;
			}
		}
		ans = max(ans, r - l);
		r--; 
	}
	ans = max(r, ans);
	cout << ans << '\n'; 
	return 0;
}
