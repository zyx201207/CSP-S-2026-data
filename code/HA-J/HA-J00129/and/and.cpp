/* record
i cannot got 100%
*/
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

#define N 200005

ll n, m, a[N], ans;
ll flagA = 1, flagB = 1;
vector<int> v[40];

inline ll dfs(ll pos, ll val, ll m) {
	if (pos > n) return 0;
	if (val == 0) return 0;
	if (m == 0) return val;
	return max(dfs(pos + 1, val, m), dfs(pos + 1, (val & a[pos]), m - 1));
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	
	flagB = ((n & (n - 1)) == 0);
	
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		
		flagA = (flagA && ((a[i] & (a[i] + 1)) == 0));
		flagB = (flagB && (a[i] == i - 1));
	}
	
	if (flagA) {
		sort(a + 1, a + n + 1, greater<int>());
		ans = (1LL << 30) - 1;
		for (int i = 1; i <= m; i++) ans &= a[i];
	} else if (flagB) {
		sort(a + 1, a + n + 1, greater<int>());
		ans = (1LL << 30) - 1;
		for (int i = 1; i <= m; i++) ans &= a[i];
	} else if (n <= 2000) {
		ans = dfs(1, (1LL << 30) - 1, m);
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 30; j++) {
				if ((a[i] >> j) & 1) v[j].push_back(i);
			}
		}
		
		for (int i = 29; i >= 0; i--) {
			if (v[i].size() == m) {
				ans = a[v[i][0]];
				for (int j = 1; j < v[i].size(); j++) ans &= a[v[i][j]];
				break;
			}
		}
	}
	
	cout << ans;

	return 0;
}
