#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e6 + 5;
int c, t, x[N], dp[N], sum[N];
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t --) {
		int n, d;
		cin >> n >> d;
		int u = 1;
		for (int i = 1; i <= n; i ++)
			cin >> x[i];
		for (int i = 2; i <= n; i ++) {
			dp[i] = x[i] - x[i - 1];
			dp[i] += dp[i - 1];
		}
		for (int i = 1; i <= n; i ++) {
			while (dp[i] - dp[u] > d)
				u ++;
			sum[i] = i - u + 1;
				
		}
	}
	cout << 0;
	return 0;
}
