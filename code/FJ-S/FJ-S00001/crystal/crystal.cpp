#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
signed main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, ans = r;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) ans = mid, r = mid - 1;
			else l = mid + 1;
		} mx = max(mx, i - ans + 1);
	} cout << mx;
	return 0;
}
