//GZ-S00098，刘信果，贵阳市第一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+5;
int c, T, n, k, dis[N], pos1, pos2, len[N], onz[N];
vector<int> g[N], zj;

void getdis(int u, int fa) {
	for (int v : g[u]) {
		if (v == fa) continue;
		dis[v] = dis[u]+1;
		getdis(v, u);
	}
}
bool getzj(int u, int fa) {
	if (u == pos2) {
		zj.push_back(u);
		return 1;
	}
	for (int v : g[u]) {
		if (v == fa) continue;
		if (getzj(v, u)) {
			zj.push_back(u);
			return 1;
		}
	}
	return 0;
}

int getneed(int u, int fa, int lim) {
	int res = 0;
	len[u] = 1;
	for (int v : g[u]) {
		if (v == fa) continue;
		res += getneed(v, u, lim);
		len[u] = max(len[u], len[v]+1);
	}
	if (res || len[u] > lim) res++, len[u] = 0;
	return res;
}
bool check(int lim) {
	if ((int)zj.size() <= lim) return 1;
	for (int lk = 1; lk < k; ++lk) {
		int rk = k-lk, li = 0, ri = 0;
		int lrem = lk, rrem = rk;
		int lcol = lim-1, rcol = zj.size()-lim;
		for (li = lim; li < zj.size(); ++li) {
			int u = zj[li];
			lrem--;
			if (lrem >= 0) lcol = li;
			for (int v : g[u]) {
				if (onz[v]) continue;
				lrem -= getneed(v, u, lim);
			}
			if (lrem < 0) break;
		}
		for (ri = zj.size()-lim-1; ri >= 0; --ri) {
			int u = zj[ri];
			rrem--;
			if (rrem >= 0) rcol = ri;
			for (int v : g[u]) {
				if (onz[v]) continue;
				rrem -= getneed(v, u, lim);
			}
			if (rrem < 0) break;
		}
		bool flag = 1;
		for (int i = li; i <= ri; ++i) {
			int s = min(i-lcol, rcol-i);
			if (s > lim) flag = 0;
			int u = zj[i];
			for (int v : g[u]) {
				if (onz[v]) continue; 
				if (getneed(v, u, lim) || len[v]+s > lim) {
					flag = 0;
					break;
				}
			}
		}
		if (flag) return 1;
	}
	return 0;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		zj.clear();
		for (int i = 1; i <= n; ++i)
			dis[i] = 0;
		getdis(1, 0);
		pos1 = 0;
		for (int i = 1; i <= n; ++i)
			if (dis[i] > dis[pos1]) pos1 = i;
		for (int i = 1; i <= n; ++i)
			dis[i] = 0;
		getdis(pos1, 0);
		pos2 = 0;
		for (int i = 1; i <= n; ++i)
			if (dis[i] > dis[pos2]) pos2 = i;
		getzj(pos1, 0);
		for (int i = 1; i <= n; ++i)
			onz[i] = 0;
		for (int u : zj)
			onz[u] = 1;
		int l = 0, r = n, ans = n;
		while (l <= r) {
			int mid = l+r>>1;
			if (!check(mid)) l = mid+1;
			else ans = mid, r = mid-1;
		}
		cout << ans << endl;
	}
	return 0;
}
