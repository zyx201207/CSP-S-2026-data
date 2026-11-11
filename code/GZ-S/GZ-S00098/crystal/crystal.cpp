//GZ-S00098，刘信果，贵阳市第一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int n, m, a[N], sum[N], ans;

int solve(int R) {
	int l = 1, r = R, res = R;
	while (l <= r) {
		int mid = l+r>>1;
		if ((R-mid+1)*a[R]-(sum[R]-sum[mid-1]) > m) l = mid+1;
		else res = mid, r = mid-1;
	} 
	return res;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i-1]+a[i];
	for (int i = 1; i <= n; ++i)
		ans = max(ans, i-solve(i)+1);
	cout << ans << endl;
	return 0;
}
