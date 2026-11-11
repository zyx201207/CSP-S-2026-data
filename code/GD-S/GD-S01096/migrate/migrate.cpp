#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

/*
long long?
freopen!!
*/
const int maxn = 2e6 + 10;

int n, d, x[maxn];

bool ck(int i, int j) {
	int res = i, tot = 0, cnt = 0, op;
	while (i < j) {
		op = lower_bound(x + 1, x + n + 1, x[i] + d + 1) - x - 1;
		//if (i == 1 && j == 4) cout << op << '\n';
		if (i == op) return 0;
		i = op;
		tot ++;
	}
	i = res;
	while (i < j) {
		if (cnt == tot - 2) break;
		i = lower_bound(x + 1, x + n + 1, x[i] + d + 1) - x - 1;
		cnt++;
	}
	return (j - i + 1 == 4);
}

void solve() {
	//³õÊ¼»¯
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			if (ck(i, j)) {
				ans ++;
				//cout << i << ' ' << j << '\n';
			}
		}
	//cout << ck(1,4) << '\n';
	cout << ans << '\n';
}


signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}

