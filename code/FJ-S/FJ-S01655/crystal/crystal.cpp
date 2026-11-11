#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 10;
int n, m;
int a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n, greater<int>());
	int j = 2, v = 0;
	while(j <= n && v + a[1] - a[j] <= m) v += a[1] - a[j], ++j;
	int ans = j - 1;
	for(int i = 2; i <= n; ++i) {
		v -= (a[i - 1] - a[i]) * (j - i);
		while(j <= n && v + a[i] - a[j] <= m) v += a[i] - a[j], ++j;
		ans = max(ans, j - i);
	}
	cout << ans << endl;
	return 0;
}

