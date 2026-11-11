#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, a[N], m;
signed main() {
	ios :: sync_with_stdio(false); 
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int j = 1, sum = 0, ans = 1;
	for (int i = 2; i <= n; i++) {
		sum += (i - j) * (a[i] - a[i - 1]);
		while (j < i && sum > m) {
			j++;
			sum -= a[i] - a[j];
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
} 
