#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int ans = 1, l = 1, now = 0;
	for (int i = 2; i <= n; ++i) {
		now += (a[i] - a[i - 1]) * (i - l); 
		while (now > m) now -= a[i] - a[l++];
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}

//CSP CP++!!!
 
