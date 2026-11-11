#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], q[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n; i++) {
		q[i] = q[i - 1] + a[i];
	}
	//cout << 3 * 91 << " " << q[3] << " " << 3 * 91 - q[3] << " " << m << "\n";
	int ans = 1;
	for (int i = 2;i <= n; i++) {
		int l = 1, r = i - 1, pos = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			int len = i - mid;
			if (len * a[i] - (q[i - 1] - q[mid - 1]) <= m) {
				r = mid - 1;
				pos = mid;
			}
			else {
				l = mid + 1;
			}
		}
		//cout << i << " " << pos << "\n";
		if (pos != -1) {
			ans = max(ans, i - pos + 1);
		}
	}
	cout << ans;
	return 0;
}
/*
3 13
91 90 78
*/
