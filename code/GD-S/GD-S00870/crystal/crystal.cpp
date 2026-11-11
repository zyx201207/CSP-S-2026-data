#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll m, a[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	ll s = 0; int j = 1, ans = 0;
	for (int i = 1; i <= n; i++, s += 1ll * (i - j) * (a[i] - a[i - 1])) {
		while (j < i && s > m) {
			s -= a[i] - a[j];
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
	
	return 0;
}
