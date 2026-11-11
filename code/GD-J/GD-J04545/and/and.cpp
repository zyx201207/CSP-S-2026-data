#include <bits/stdc++.h>
using namespace std;
int dp[200005], a[200005];
bool d[200005];

int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
		if (a[i] > dp[1]) dp[1] = a[i];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!d[j]) {
				d[j] = true;
				dp[i] = max (dp[i - 1], dp[i - 1] & a[j]);
			}
		}
		memset(d,0,sizeof(d));
	}
	cout << dp[m];
	return 0;
}
