#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, msk, ans, x[15], y[15], dis[15][15];
void solve1() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j)  dis[i][j] = 0;
			else  dis[i][j] = n;
		}
	}
	for(int i = 2; i <= n; i++) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		dis[x[i]][y[i]] = dis[y[i]][x[i]] = 1;
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	msk = 1 << n, ans = n;
	for(int st = 1, cnt, mx, mn; st < msk; st++) {
		cnt = 0;
		for(int i = 0; i < n; i++) {
			if(st >> i & 1)  cnt++;
		}
		if(cnt > k)  continue;
		for(int i = 2; i <= n; i++) {
			if((st >> x[i] & 1) && (st >> y[i] & 1))  cnt--;
		}
		if(cnt > 2)  continue;
		mx = 0;
		for(int i = 0; i < n; i++) {
			mn = n;
			for(int j = 0; j < n; j++) {
				if(st >> j & 1)  mn = min(mn, dis[i][j]);
			}
			mx = max(mx, mn);
		}
		ans = min(ans, mx);
	}
	cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		if(c <= 3)  solve1();
	}
	return 0;
}
