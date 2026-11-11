#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], s[N], ans;
bool check(int l, int r) {
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m; 
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int lb = i, ub = n + 1, mid;
		while (ub - lb > 1) {
			mid = ub + lb >> 1;
			if (check(i, mid)) lb = mid;
			else ub = mid;
		}
		ans = max(ans, lb - i + 1);
	}
	cout << ans;
}
