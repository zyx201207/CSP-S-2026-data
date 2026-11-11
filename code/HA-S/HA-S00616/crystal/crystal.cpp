#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int n, m, a[N], s[N], ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r)>>1;
			if (m >= (i - mid + 1) * a[i] - (s[i] - s[mid-1])) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}
