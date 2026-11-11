#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, fa[500005], v[500005];
vector<int> a;
struct node {
	int u, v, w;
};
vector<node> e;
vector<pair<int, int>> ee[500005]; 
bool cmp(node x, node y){
	return x.w < y.w;
}
int find(int x) {
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void ks() {
	for(auto i : e) {
		int fx = find(i.u), fy = find(i.v);
		if(fx != fy) {
			fa[fy] = fx;
			ee[i.u].push_back({i.v, i.w});
			ee[i.v].push_back({i.u, i.w});
		}
	}
}
int ans = -1;
void dfs(int x, int y, int use) {
	if(x == y) {
		if(ans == -1)
			ans = use;
		else
			ans = min(use, ans);
	}
	for(auto i : ee[x]) {
		if(!v[i.first]) {
			v[i.first] = 1;
			dfs(i.first, y, use + i.second);
			v[i.first] = 0;
		}
	}
	return;
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		int t;
		cin >> t;
		fa[t] = t;
		a.push_back(t);
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int lid, lt;
		for(int j = 1; j <= k; j++) {
			int id, t;
			cin >> id >> t;
			if(j != 1) {
				e.push_back({lid, id, lt + t});
				e.push_back({id, lid, lt + t});
			}
			lid = id;
			lt = t;
		}
	}
	sort(e.begin(), e.end(), cmp);
	ks();
	while(q--) {
		int tl , r2;
		cin >> tl >> r2;
		ans = -1;
		dfs(tl, r2, 0);
		cout << ans + a[tl - 1] + a[r2 - 1] << endl;
	}
}
