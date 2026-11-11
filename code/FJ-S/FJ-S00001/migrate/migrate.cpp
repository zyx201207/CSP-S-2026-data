#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, t, n, d, x[N], nxt[N], tag[N], f[N][2];
vector<int> lst[N];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i], lst[i].clear();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i][0] = f[i][1] = tag[i] = 0;
		nxt[i] = max(i, nxt[i - 1]);
		while(nxt[i] < n && x[nxt[i] + 1] - x[i] <= d) nxt[i] ++;
		lst[nxt[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		int r = nxt[i];
		if(r == i || r == n || r == i + 1) continue;
		int rr = nxt[r];
		if(r == rr) continue;
		int R = min(rr, nxt[r - 1]);
		int L = max(r + 1, nxt[r - 2] + 1);
		ans += R - L + 1;
	}
	for (int i = 3; i <= n; i++) {
		int r = nxt[i];
		if(i == r) continue;
		if(x[r] - x[i - 1] <= d && x[r] - x[i - 2] > d) tag[i] = 1;
		else if(x[r] - x[i - 2] <= d) tag[i] = 2;
	} 
	for (int i = 1; i <= n; i++) {
		int r = nxt[i];
		if(i == r) continue;
		if(nxt[r] == r) continue;
		if(tag[r] == 1) f[r][1] ++;
		else if(tag[r] == 0) f[r][0] ++;
	}
	for (int i = 1; i <= n; i++) {
		int r = nxt[i];
		if(i == r) continue;
		if(nxt[r] == r) continue;
		if(tag[r] == 1) {
			if(x[r - 1] - x[i - 1] > d) f[r][1] += f[i][0];
		} else if(tag[r] == 0) {
			f[r][0] += f[i][0];
			f[r][1] += f[i][1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if(!f[i][0] && !f[i][1]) continue;
		int r = nxt[i];
		if(i == r) continue;
		if(nxt[r] == r) continue;
		int L = max(r + 1, nxt[r - 1] + 1);
		ans += max(0ll, nxt[r] - L + 1) * f[i][1];
		if(x[r - 1] - x[i - 1] > d) {
			L = max(nxt[r - 2] + 1, r + 1);
			ans += max(0ll, nxt[r - 1] - L + 1) * f[i][0];
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
