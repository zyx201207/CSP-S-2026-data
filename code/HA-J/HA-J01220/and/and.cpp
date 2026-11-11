#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], m;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	if (m == n) {
		for (int i = 1; i <= n; i++)
			ans &= a[i];
	}
	if (m == n - 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int maxx = 1;
				if (j == i)
					continue;
				maxx\ &= a[j];
			}
			ans =  max(ans, max);
		}
	}
	if (m == 1) {
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(a[i], ans);
	}
	else{
		for (int i = n; i >= n - m + 1; i++)
			ans &= a[i];
	}
	cout << ans;
	return 0;
}