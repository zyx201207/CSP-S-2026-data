/**
 * @file CSP-J 2026
 *       Problem C. and
 * @author BJ-J01847
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/

// Straight into the lights I found myself...
// Straight Into the Lights - Cosmograph

// password: Trick||Treat!

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m, a[N], ans;
vector<int> v;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int j = 29; ~j; --j) {
		for (int i = 1; i <= n; ++i)
			if (a[i] >> j & 1)
				v.push_back(a[i]);
		if (v.size() < m) {
			vector<int>().swap(v);
			continue;
		}
		for (int i = 1; i <= v.size(); ++i)
			a[i] = v[i - 1];
		n = v.size();
		vector<int>().swap(v);
		ans |= 1 << j;
	}
	cout << ans << '\n';
	return 0;
}

//09:18