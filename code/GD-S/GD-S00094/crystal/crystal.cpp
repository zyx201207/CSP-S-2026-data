#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int sum[500010];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	sum[0] = 0;
	for(int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	int p = 1;
	for(int i = 1; i <= n; i ++) { 
		while((i - p + 1) * a[i] - (sum[i] - sum[p - 1]) > m && p < i) {
			p ++; 
		}	 
		ans = max(ans, i - p + 1);
	}
	cout << ans;
	return 0;
} 
