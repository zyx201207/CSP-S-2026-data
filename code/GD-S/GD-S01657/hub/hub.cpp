#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
const int N = 4000 + 5;

ll subid;
int n, k;
vector<int> e[N];
int fa[N], sz[N];
int dfn[N], cur = 0;
int d[N] = {}, len[N] = {};
int st[20][N], pw[20], lg[N];
vector<int> ord;
void dfs(int x, int pr) {
	fa[x] = pr;
	dfn[x] = ++cur;
	st[0][dfn[x]] = pr;
	ord.pb(x);
	len[x] = 0;
	sz[x] = 1;
	for (auto i: e[x])
		if (i != pr) {
			d[i] = d[x] + 1;
			dfs(i, x);
			len[x] = max(len[x], len[i] + 1);
			sz[x] += sz[i];
		}
}
inline int sml(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
void init() {
	cur = 0;
	d[1] = 0;
	dfs(1, 0);
	pw[0] = 1;
	for (int i = 1; i < 20; i++)
		pw[i] = pw[i - 1] << 1;
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i < 20; i++)
		for (int j = 1; j + pw[i] - 1 <= n; j++)
			st[i][j] = sml(st[i - 1][j], st[i - 1][j + pw[i - 1]]);
}
inline int lca(int x, int y) {
	if (x == y)
		return x;
	x = dfn[x], y = dfn[y];
	if (x > y)
		swap(x, y);
	int s = lg[y - x];
	return sml(st[s][x + 1], st[s][y - pw[s] + 1]);
}
inline int dist(int x, int y) {
	return d[x] + d[y] - 2 * d[lca(x, y)];
}

int lim;

int cnt[N];
void srh(int x, int pr) {
	cnt[x] = 0;
	for (auto i: e[x])
		if (i != pr) {
			srh(i, x);
			cnt[x] += cnt[i];
		}
	if (len[x] >= lim)
		cnt[x]++;
}

int rt1;
bool _us[N] = {};
int len2[N] = {}, cnt2[N] = {};
void dfs2(int x, int pr) {
	if ((dfn[rt1] <= dfn[x] && dfn[x] <= dfn[rt1] + sz[rt1] - 1) || dist(x, rt1) <= lim)
		_us[x] = 0;
	else
		_us[x] = 1;
	len2[x] = 0;
	for (auto i: e[x])
		if (i != pr) {
			dfs2(i, x); 
			_us[x] = _us[x] || _us[i];
			if (_us[i])
				len2[x] = max(len2[x], len2[i] + 1);
		}
}
void srh2(int x, int pr) {
	if (!_us[x])
		return ;
	cnt2[x] = 0; 
	for (auto i: e[x])
		if (i != pr && _us[i]) {
			srh2(i, x);
			cnt2[x] += cnt2[i];
		}
	if (len2[x] >= lim)
		cnt2[x]++;
}
int rres;
void srh22(int x, int pr, int outd) {
	if (outd <= lim)
		rres = min(rres, cnt2[x]);
	else
		return ;
	vector<int> pre, suf, son;
	for (int i = 0; i < e[x].size(); i++)
		if (e[x][i] != pr && _us[e[x][i]]) {
			son.pb(e[x][i]);
		}
	pre.resize(son.size());
	suf.resize(son.size());
	for (int i = 0; i < son.size(); i++)
		pre[i] = suf[i] = len2[son[i]];
	for (int i = 1; i < son.size(); i++)
		pre[i] = max(pre[i - 1], pre[i]);
	for (int i = son.size() - 2; i >= 0; i--)
		suf[i] = max(suf[i + 1], suf[i]);
	
	for (int i = 0; i < son.size(); i++) {
		int lmx = (i == 0 ? 0 : pre[i - 1] + 2);
		int rmx = (i == son.size() - 1 ? 0 : suf[i + 1] + 2);
		srh22(son[i], x, max(outd + 1, max(lmx, rmx)));
	}
}

bool chk(int _x) { //<=xÊÇ·ñ¿ÉÐÐ 
//	cerr << "chk " << _x << '\n';
	lim = _x;
	srh(1, 0);
	for (int i = 1; i <= n; i++) {
//		cerr << "do " << i << '\n';
		rt1 = i;
		ll res = max(1, cnt[i]);
		
		int rt = -1;
		for (int j = 1; j <= n; j++)
			if (!(dfn[i] <= dfn[j] && dfn[j] <= dfn[i] + sz[i] - 1)) {
				if (dist(i, j) > lim) {
					rt = j;
					break;
				}
			}
//		cerr << i << ":" << rt << ',' << cnt[i] << '\n';
		if (rt == -1) {
			if (res <= k)
				return true;
			continue;
		}
		
		for (int j = 1; j <= n; j++)
			_us[j] = len2[j] = cnt2[j] = 0;
		dfs2(rt, 0);
		srh2(rt, 0);
		rres = n + 1;
		srh22(rt, 0, 0);
		
//		cerr << "WOW " << rres << '\n';
		
		if (res + rres <= k)
			return true;
	}
//	cerr << "done\n";
	return false;
}

void slv() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		vector<int>().swap(e[i]);
	vector<int>().swap(ord);
	
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	init();
	 
//	cout << chk(16) << ' ' << chk(17) << '\n';
	
//	cout << chk(300) << '\n';
//	cout << chk(5) << ' ' << chk(6) << '\n';
//	cout << chk(8) << ' ' << chk(9) << '\n';
//	cout << "\n";
//	return ;
	int l = -1, r = n - 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
//		cerr << "! " << mid << ' ' << l << ' ' << r << "\n";
//		cerr << chk(mid) << '\n';
		if (chk(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << '\n';
}

int main() {
//	freopen("hub3.in", "r", stdin);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> subid;
	int T = 1;
	cin >> T;
//	T = 1;
	while (T--)
		slv();
	return 0;
}
