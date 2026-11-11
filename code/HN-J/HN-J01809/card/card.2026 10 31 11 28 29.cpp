#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5;
int n, m, x;
int a[N], b[N], buck[N], ansb[N];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = k; i <= n; i ++) {
			buck[a[i]] ++;
		}
	}
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
//	cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}

