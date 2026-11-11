#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], tmp[N], tot, vis[N], ans[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			bool flag = 0;
			for (int k = tot; k >= 1; k --) {
				if (a[j] == tmp[k]) {
					tmp[k] = a[j], tot = k;
					flag = 1;
					break;
				}
			}
			if (!flag) tmp[++ tot] = a[j];
		}
		for (int j = 1; j <= tot; j ++) {
			if (!vis[tmp[j]]) {
				vis[tmp[j]] = 1, ans[tmp[j]] ++;
			}
		}
		memset(vis, 0, sizeof vis);
		tot = 0;
	}
	for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
	return 0;
}
