#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
ll a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; ll m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			ll f = (i - mid) * 1LL * a[i] - (sum[i - 1] - sum[mid - 1]);
			if (f <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	
	return 0;
}
