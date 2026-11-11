// 0

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kM = 3e5 + 7;

int n, m, a[kM], ans[kM], pd[kM], vis[kM];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int w = 0, cnt = 0;
		fill(pd + 1, pd + n + 1, 0);
		fill(vis + 1, vis + m + 1, -1); 
		for (int j = i; j <= n; j++) {
			cnt++;
			if (vis[a[j]] == -1) {
				vis[a[j]] = cnt;
				pd[++w] = a[j];
			} else {
				w = vis[a[j]];
				vis[a[j]] = cnt;
			}
		}
		for (int i = 1; i <= w; i++) {
			ans[pd[i]]++;
//			cout << pd[i] << " ";
		}
//		cout << "\n";
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
/*
4 3
1 2 1 3
3 1 4

10 3

*/
