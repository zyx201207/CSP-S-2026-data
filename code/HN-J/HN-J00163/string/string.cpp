#include<bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int n, l, r, ans, a[200005];
char c[200005];
void solve() {
	cin >> n, l = 1, r = n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	while (l < r) {
		if (c[l] == c[r]) {
			if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else {
				a[l] = a[r] = 0;
				l++, r--;
			}
		} else {
			if (a[l] < a[r]) {
				ans += a[l];
				a[r] -= a[l];
				l++;
			} else if (a[l] > a[r]) {
				ans += a[r];
				a[l] -= a[r];
				r--;
			} else {
				ans += a[l];
				a[l] = a[r] = 0;
				l++, r--;
			}
		}
	}
	cout << ans;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}

