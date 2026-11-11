//GZ-S00361 遵义四中 余学森 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
ll n, m, a[N], pre[N], ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		ll l = 1, r = i, res = i;
		while (l <= r) {
			int j = (l + r) >> 1;
			if ((i - j + 1) * a[i] - (pre[i] - pre[j - 1]) <= m) res = j, r = j - 1;
			else l = j + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}
