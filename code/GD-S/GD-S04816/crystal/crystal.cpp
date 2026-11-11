#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], s[N], ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) 
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, pos = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - s[i] + s[mid - 1] <= m) {
				r = mid - 1;
				pos = mid;
			} else {
				l = mid + 1;
			}
		}
		if (!~pos) continue;
		ans = max(ans, i - pos + 1);
	}
	cout << ans << endl;
	return 0;
}
