#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N], vis[N], cg[N], ans;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i], vis[i] = 1;
	}
	for (int i = 31; i >= 0; i --) {
		int val = (1 << i);
		for (int j = 1; j <= n; j ++) {
			cg[j] = 0;
			if ((a[j] & val) == 0 && vis[j]) vis[j] = 0, cg[j] = 1;
		}
		int cnt = 0;
		for (int j = 1; j <= n; j ++) {
			cnt += vis[j];
		}
		if (cnt >= m) ans += val;
		else {
			for (int j = 1; j <= n; j ++) {
				if (cg[j]) vis[j] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
