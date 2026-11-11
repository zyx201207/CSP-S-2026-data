/*
5 5
1 2 4 8 9
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace hz {
	int n, m;
	int a[5000005], s[5000005];
	map<int, int>p;
	signed main() {
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			s[i] = s[i - 1] + a[i];
		}
		int r = 1, ans = 0;
		for (int l = 1; l <= n; l++) {
			while (a[l] * (l - 1)  - (s[l] - s[r - 1]) > m) {
				r++;
			}
			ans = max(ans, l - r + 1);
		}
		cout << ans << endl;
		return 0;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	hz::main();
	return 0;
}
