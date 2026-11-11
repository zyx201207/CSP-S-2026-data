#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int n, m, a[N], s[N], l, r, v, ans;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0),
	cin.tie(0), cin >> n >> m;
	for (int i = 1; i <= n; i ++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i];
	l = r = 1;
	while (r < n && v <= m)
		v += (a[r + 1] - a[r]) * (r - l + 1), r ++;
	if (v <= m)ans = r - l + 1;
	while (l <= r && r < n){
		v -= a[r] - a[l ++];
//		while (v > m && l < r)v -= a[r] - a[l ++];
		if (v <= m)ans = max(ans, r - l + 1);
		while (r < n && v <= m)
			ans = max(ans, r - l + 1),
			v += (a[r + 1] - a[r]) * (r - l + 1), r ++;
	}return cout << ans, 0;
}
