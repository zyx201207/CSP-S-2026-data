#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 5e5 + 10;
ll a[maxn], sum[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[i] * (i - mid) - (sum[i] - sum[mid]) <= m) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, (ll)i - l);
	}
	cout << ans;
	return 0;
}
