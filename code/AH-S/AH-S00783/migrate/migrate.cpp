#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5; 
struct node {
	int mn, mncnt, times;
}f[N];
int a[N];
void solve() {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int ans = 0;
	for (int begin = 2; begin < n; ++begin) {
		memset(f, 0, sizeof f);
		f[begin - 1] = {0, 1, 0};
		for (int i = begin; i <= n; ++i) {
			int mn = INT_MAX, mncnt = 0, mnadd = 0;
			for (int j = i - 1; j >= begin - 1; --j) {
				if (a[i] - a[j] > d) break;
				if (f[j].mn < mn) {
					mn = f[j].mn;
					mncnt = f[j].mncnt;
					mnadd = f[j].times + 1;
				}
				else if (f[j].mn == mn) mncnt += f[j].mncnt;
			}
			f[i] = {mn + mnadd, mncnt, mnadd};
			if (f[i].mncnt == 2) ans++;
		}
	}
	// for (int i = 1; i <= n; ++i) cout << f[i].mncnt << " ";
	// cout << endl; 
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int AC;
	cin >> AC;
	int _;
	cin >> _;
	while (_--) solve();
	return 0;
}

// CSP RP++!!!
