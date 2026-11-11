#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+1+n);
	a[0] = a[1];
	int l = 1, ans = 0, cnt = 0;
	for (int r = 1; r <= n; ++r) {
		cnt += (r-l) * (a[r] - a[r-1]);
		while(l < r && cnt > m) l++, cnt -= a[r]-a[l];
		ans = max(ans, r-l+1);
	}
	cout << ans;
	return 0;
}

