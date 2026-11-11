#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
map<ll, int> mp;
ll m, a[N];
void Solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++mp[a[i]];
	}
	int ans = 0;
	sort(a + 1, a + n + 1);
	ll s = 0;
	for (int i = 1, l = 1; i <= n; ++i) {
		s += a[i];
		while ((i - l + 1) * a[i] - s > m) s -= a[l++];
		ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) Solve();
	return 0;
}
