#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
//#define MUL_TEST
#define FILENAME "crystal"
using namespace std;
int a[500005], sa[500005];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sa[i] = sa[i - 1] + a[i];
	}
	
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n) {
			int res = (j - i + 1) * a[j] - (sa[j] - sa[i - 1]);
			if (res > m) {
				j--;
				break;
			}
			j++;
		}
		ans = max(ans, min(j, n) - i + 1);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	#ifdef USE_FREOPEN
		freopen(FILENAME ".in", "r", stdin);
		freopen(FILENAME ".out", "w", stdout);
	#endif
	
	int _ = 1;
	#ifdef MUL_TEST
		cin >> _;
	#endif
	while (_--) solve();
	
	_ ^= _;
	return (0^_^0);
}
