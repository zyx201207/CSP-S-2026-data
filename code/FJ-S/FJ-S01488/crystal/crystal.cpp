#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 2;

int n, m, ans, a[N], b[N], c[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1;i <= n;i++) b[i] = b[i - 1] + a[i];//, cout << b[i] << endl;
//	cout << endl;
	for (int i = 1;i <= n;i++) {
		int l = 1, r = i, best = 0;
		while (l <= r) {
			int mid = l + ((r - l) >> 1);
			int res = mid * a[i] - (b[i] - b[i - mid]);
			if (res <= m) l = mid + 1, best = mid;
			else r = mid - 1;
		}
		ans = max(ans, best);
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
