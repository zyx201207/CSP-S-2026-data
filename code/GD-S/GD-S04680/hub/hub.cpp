#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int C, T, n, k, num, cnt, dfn[N], d[N], mx, fa[N][22], lst[N];
bool vis[N];
vector<int> v[N];
void tf(int u, int ff){
	d[u] = d[fa[u][0] = ff] + 1, dfn[u] = ++ num;
	for (int i = 1; (1 << i) <= d[u]; i ++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto e : v[u])if (e != ff)tf(e, u);
}void dfs(int u){
	for (auto e : v[u])
		if (e != fa[u][0])dfs(e),
		lst[u] = min(lst[u], lst[e] + 1);
	if (lst[u] > mx){
		int lt = mx, e = u;
		for (int i = 21; i + 1 && lt; i --)
			if ((1 << i) <= lt)
				lt -= (1 << i), e = fa[e][i];
		e = max(e, 1), cnt += !vis[e], vis[e] = 1,
		lst[u] = mx, lst[fa[u][0]] = !mx ? 1 : mx - 1;
	}
}bool check(){
	for (int i = 1; i <= n; i ++)
		lst[i] = N, vis[i] = 0;
	cnt = 0, dfs(1);if (cnt > k)return 0;
	vector<pair<int, int> > nv;
	for (int i = 1; i <= n; i ++)
		if (vis[i])nv.push_back({dfn[i], i});
	if (nv.size() <= 2 || !mx)return 1;
	sort(nv.begin(), nv.end(), greater<pair<int, int> > ());
	for (int i = 1; i < nv.size(); i ++)
		if (d[nv[i].second] < d[nv[i - 1].second])
			cnt += d[nv[i - 1].second] - d[nv[i].second] - 1;
	return cnt <= k;
}int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0),
	cin.tie(0), cin >> C >> T;
	while (T -- && cin >> n >> k){
		for (int i = 1; i <= n; i ++)v[i].clear();
		for (int i = 1, x, y; i < n; i ++)
			cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
		int l = 0, r = n, ans = n;
		num = 0, tf(1, 0);while (l <= r)
			mx = l + r >> 1, (check() ?
			r = (ans = mx) - 1 : l = mx + 1);
		cout << ans << '\n';
	}return 0;
}
/*
0 1
6 5
1 2
2 5
4 5
5 3
3 6
*/
