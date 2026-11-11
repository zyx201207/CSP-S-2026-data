#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k, cnt, u[N], v[N];
vector<int> G[N], pos;
void clear() {
	
}
void add(int x, int y) {
	G[x].push_back(y);
}
void dfs1(int x, int fa) {
	pos.push_back(x);
	for (auto y : G[x]) {
		if (y == fa) continue;
		dfs1(y, x);
	} 
	return;
}
int dfs2(int x, int fa, int dep, int lim) {
	int mxd = 0;
	if (G[x].size() == 1) mxd = dep;
	for (auto y : G[x]) {
		if (y == fa) continue;
		mxd = max(mxd, dfs2(y, x, dep + 1, lim));
	}
	if (!fa || mxd - dep >= lim) cnt += 1;
	return mxd; 
}
int calc(int rt, int lim) {
	pos.clear();
	dfs1(rt, 0);
	int tmp = n;
	for (auto R : pos) {
		cnt = 0;
		dfs2(R, 0, 0, lim);
		tmp = min(tmp, cnt);
	}
	return tmp;
}
bool check(int lim) {
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) G[j].clear();
		for (int j = 1; j < n; j++) {
			if (j != i) {
				add(u[j], v[j]);
				add(v[j], u[j]);
			}
		}
		res = calc(u[i], lim) + calc(v[i], lim);
		if (res <= k) return 1;
	}
	return 0;
}
void work() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) cin >> u[i] >> v[i];
	int L = 0, R = n, mid;
	while (L < R) {
		mid = (L + R) >> 1;
		if (check(mid)) R = mid;
		else L = mid + 1;
	}
	cout << R << '\n';
	return;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T; cin >> c >> T;
	while (T--) work(), clear();
	return 0;
}