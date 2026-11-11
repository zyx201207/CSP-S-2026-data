#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n, m, ans = 0;
ll a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	ll ma = -1e18, mi = 1e18;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
	}
	sort(a + 1, a + n + 1);
	ll mm = m, c = 1;
	for (int i = 1; i <= n; i++) {
		mm = m, c = 1;
		for (int j = i-1; j >= 1; j--) {
			if (mm < abs(a[i] - a[j])) {
				break;
			} else {
				mm -= abs(a[i] - a[j]);
				c++;
			}
		}
		ans = max(ans, c);
	}
	cout << ans << '\n';
	return 0;
}
