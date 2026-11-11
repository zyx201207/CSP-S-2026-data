#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int n, d, a[N];
void solve() {
	cin >> n >> d;
	for (int i = 1;i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1;i <= n; i++) {
		for (int j = i + 1;j <= n; j++) {
			int sum = 0; 
			for (int k = i + 1;k < j; k++) {
				if (a[k] - a[i] <= d && a[j] - a[k] <= d) {
					sum++;
				}
			}
			//cout << i << " " << j << " " << sum << "\n";
			if (sum == 2) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return ;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	} 
	return 0;
}
/*
0 1
10 3
-1000000000000000000
-999999999999999997    0
-999999999999999994    2
-999999999999999993    1
-999999999999999992    1
-999999999999999991    1
-999999999999999990    
-999999999999999989
-999999999999999986
-999999999999999983
0 1
10 3
-1000000000000000000
-999999999999999997
-999999999999999994
-999999999999999993
-999999999999999992
-999999999999999991
-999999999999999990
-999999999999999989
-999999999999999986
-999999999999999983
*/
