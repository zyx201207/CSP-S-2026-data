#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], s[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];		
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		s[i] = s[i + 1] + a[i]; 
	}
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int l = 0, r = i;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			int k = s[mid] - s[i];
			if (a[i] * (i - mid) - k <= m) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans << '\n';
	return 0;
} 
