#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + 1 + n);
	a[0] = a[1];
	int l = 1, sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += (i - l) * (a[i] - a[i - 1]);
		if (sum <= m) ans = max (ans, i - l + 1);
		else {
			while (sum > m) {
				sum -= a[i] - a[l];
				l ++;
			}
			ans = max(ans, i - l + 1);
		}
	}
	cout << ans << '\n';
	return 0;
} 
