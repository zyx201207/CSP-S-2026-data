#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[500005], ans, cnt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for (int l = 1, r = 1; r <= n; ++r) {
		while (cnt > m && l <= r) {
			cnt -= a[r] - a[l];
			l++;
		}
		if (cnt <= m) {
			ans = max(ans, r - l + 1);
		}
		
		cnt += (r - l + 1) * (a[r + 1] - a[r]);
	}
	
	cout << ans;
	
	return 0;
}
