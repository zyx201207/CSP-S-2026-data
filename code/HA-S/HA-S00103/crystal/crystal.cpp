#include<bits/stdc++.h>
using namespace std;
/*
AC at 15:00
yuan lai bu shi xian duan shu shang er fen a
*/
#define N 500005
#define int long long
int n, m, a[N], ans = 1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, sum = 0;
	for (int r = 2; r <= n; r++) {
		sum += (r - l) * (a[r] - a[r - 1]);
		while (sum > m) {
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
