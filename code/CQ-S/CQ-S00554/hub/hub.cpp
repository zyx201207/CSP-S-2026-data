#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, k, flg[N + 5], dst[15][15];
vector<int> G[N + 5];
int ck() {
	int ret = 0;
	for(int i = 1; i <= n; i ++) {
		for(auto j : G[i]) if(flg[i] && flg[j]) ret ++;
	}
	return ret / 2;
}
int get_ans() {
	int ret = 0;
	for(int i = 1; i <= n; i ++) {
		int p = n;
		for(int j = 1; j <= n; j ++) if(flg[j]) p = min(p, dst[i][j]);
		ret = max(ret, p);
	}
	return ret;
}
void deal() {
	int ans = n;
	for(int i = 1; i < (1 << n); i ++) {
		int cnt = 0, x = i;
		while(x) cnt ++, x -= x & -x;
		for(int p = 1; p <= n; p ++) flg[p] = (1 << (p - 1)) & i;
		if(cnt <= k && cnt - ck() <= 2) {
			ans = min(ans, get_ans());
		}
	}
	cout << ans << '\n';
	return;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> k;
		for(int i = 1; i <= n; i ++) G[i].clear();
		for(int i = 1; i < n; i ++) {
			int x, y;
			cin >> x >> y;
			G[x].emplace_back(y), G[y].emplace_back(x);
		}
		if(c <= 3) {
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= n; j ++) {
					dst[i][j] = n + 5;
				}
				dst[i][i] = 0;
			}
			for(int x = 1; x <= n; x ++) for(auto y : G[x])
				dst[x][y] = dst[y][x] = 1;
			for(int k = 1; k <= n; k ++) {
				for(int i = 1; i <= n; i ++) {
					for(int j = 1; j <= n; j ++) {
						dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
					}
				}
			}
			deal();
		} else if(k == n) {
			cout << "0\n";
		} else if(k >= n / 2) {
			cout << "1\n";
		} else {
			n /= 2;
			cout << ((n - k + 1) / 2 + 2) / 2 << '\n';
		}
	}
	return 0;
}

