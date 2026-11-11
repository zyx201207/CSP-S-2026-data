#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int c, T, n, ts, u[N], v[N], fa[N], dep[N], md[N], del[N], c1[N], c2[N], mx, k;
vector <int> e[N];
void dfs(int x, int p){
	dep[x] = dep[p] + 1, fa[x] = p;
	if(dep[x] > dep[mx]) mx = x;
	for(int i: e[x]) if(!del[i] && i != p) dfs(i, x);
}
void dfs2(int x, int p, int *c){
	md[x] = 0;
	for(int i: e[x]) if(!del[i] && i != p) dfs2(i, x, c), md[x] = max(md[x], md[i] + 1);
	c[md[x]]++;
}
void slv(int rt, int *c){
	mx = 0, dfs(rt, 0);
	rt = mx, mx = 0; dfs(rt, 0);
	int w = dep[mx];
	for(int i = 1; i <= w / 2; i++) mx = fa[mx];
	dfs2(mx, 0, c);
	for(int i = n - 1; ~i; i--) c[i] += c[i + 1];
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i < n; i++) cin >> u[i] >> v[i], e[u[i]].push_back(v[i]), e[v[i]].push_back(u[i]);
		if(n <= 4000){
			int ans = n;
			slv(1, c1);
			for(int j = 0; j < n; j++) if(c1[j] && c1[j] <= k) ans = min(ans, j);
			for(int j = 0; j <= n; j++) c1[j] = c2[j] = 0;
			for(int i = 1; i < n; i++){
				del[u[i]] = 1, slv(v[i], c1), del[u[i]] = 0;
				del[v[i]] = 1, slv(u[i], c2), del[v[i]] = 0;
				for(int j = 0; j < n; j++) if(max(c1[j], 1) + max(c2[j], 1) <= k) ans = min(ans, j);
				for(int j = 0; j <= n; j++) c1[j] = c2[j] = 0;
			}
			cout << ans << '\n';
		} else{
			if(k == n) cout << "0\n";
			else if(k >= n / 2) cout << "1\n";
			else cout << (n / 2 + 7 - k) / 4 << '\n';
		}
		for(int i = 1; i <= n; i++) e[i].clear();
	}
	return 0;
}
