#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;

int c, t, x[N], d, n, cnt[N][N], mn[N][N], ans;

void dfs(int s, int t, int nw, int dis) {
	if(nw == t) {
		if(dis == mn[s][t]) cnt[s][t]++;
		if(dis < mn[s][t] || mn[s][t] == -1) {
			mn[s][t] = dis;
			cnt[s][t] = 0;
		}
		return;
	}
	for(int i = nw + 1;i <= n && x[i] - x[nw] <= d;i++) {
		dfs(s, t, i, dis - x[i] + x[nw]);
	}
}

int main() {
	freopen("migrate3.in", "r", stdin);
//	freopen("migrate1.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		for(int i = 1;i <= n;i++) {
			for(int j = i + 1;j <= n;j++) {
				memset(cnt, 0, sizeof cnt);
				memset(mn, -0x00000001, sizeof mn);
				dfs(i, j, i, 0);
				ans += (cnt[i][j] == 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
