#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int n, m, ans;
int a[N], s[N];
bool check(int x, int r) {
	return (a[r]*(r-x+1)-(s[r]-s[x-1]) <= m);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.ouw", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	for (int i = 1; i <= n; i++) {
		if (i != n && a[i] == a[i+1]) continue;
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = (l+r)>>1;
			if (check(mid, i)) r = mid-1, res = mid;
			else l = mid+1;
		}
		ans = max(ans, i-res+1);
	} 
	cout << ans << '\n';
	return 0;
}
