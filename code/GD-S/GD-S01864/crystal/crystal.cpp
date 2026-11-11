#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
int n, m, a[maxn];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i]; sort(a + 1, a + n + 1);
	int s = 0, ans = 0, lx = 0;
	for (int i = 1; i <= n; i++) {
		s += a[i];
		while(a[i] * (i - lx) - s > m)
			lx++, s -= a[lx];
		ans = max(ans, i - lx);
	}
	cout << ans << endl;
	return 0;
} 
