#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int n, m, a[N], p[N], ans = 1;

signed main () {
	ios :: sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) p[i] = p[i - 1] + a[i];
	
	for (int i = 2; i <= n; i ++) {
		int l = 1, r = i - 1, zl = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (p[i - 1] - p[mid - 1] + m >= a[i] * (i - 1 - mid + 1)) {
				zl = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
//		cout << i << " " << zl << "\n";
		ans = max (ans, i - zl + 1);
	}
	
	cout << ans;
	
	return 0;
}
