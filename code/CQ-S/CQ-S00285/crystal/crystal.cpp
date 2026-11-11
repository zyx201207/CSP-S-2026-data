/*
14:35
*/ 
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 5e5 + 5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f3f3f3f3f;
int test = 1, tt = 1;
int n, m, a[N], sum[N];

bool check(int l, int r) {
	int res = sum[r] - sum[l - 1];
	res = (r - l + 1) * a[r] - res;
	return res <= m;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i]; 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, mid, pos = i;
		while (l <= r) {
			mid = l + r >> 1;
			if (check(mid, i)) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - pos + 1);
	}
	cout << ans << '\n';
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> test;
	for (; tt <= test; tt++) {
		solve();
	}
}
/*
5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

