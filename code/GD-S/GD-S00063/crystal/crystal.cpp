#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;
const int N = 5e5 + 10, inf = 1e18, M = 2e6 + 10;
int n, m, a[N], sum[N];
bool check(int X) {
	bool fl = 0;
	for(int l = 1; l + X - 1 <= n; l++) {
		int r = l + X - 1;
		int num = a[r] * X - (sum[r] - sum[l - 1]);
		fl |= (num <= m);
	}
	return fl;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, ans = 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}
/*
½ñÌìÄÖÂðÁË 
*/
