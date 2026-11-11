#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 10;
int c, n, m, d, q;
int w[maxm];
struct node{
	int line, t;
};
vector<node> g[maxm], s[maxm];
int ans = 0x3f3f3f3f;
bool vis[maxm];
void dfs(int u, int e, int num){
	if(u == e){
		ans = min(num, ans);
		return;
	}
	vis[u] = 1;
	for(node nxt : g[u]){
		int line = nxt.line;
		int t = nxt.t;
		for(auto v : s[line]){
			int nv = v.line;
			int nd = v.t;
			if(vis[nv]) continue;
			dfs(nv, e, num + t + nd);
		}
	}
	vis[u] = 0;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			s[i].push_back({a, t});
			g[a].push_back({i, t});
		}
	}
	while(q--){
		memset(vis, 0, sizeof vis);
		ans = 0x3f3f3f3f;
		int x, y;
		cin >> x >> y;
		dfs(x, y, 0);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}