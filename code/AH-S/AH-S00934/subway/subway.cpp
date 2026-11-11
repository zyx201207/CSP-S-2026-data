#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int c, n, m, d, q, s, e;
int w[N], k[N];
int a[505][100005], t[505][100005];
bool vis[N];
long long ans = LLONG_MAX;
struct node{
	int v, h;
};
vector<node> g[N];
void add(int id1, int id2, int bh){
	g[id1].push_back({id2, bh});
	g[id2].push_back({id1, bh});
}
void dfs(int sr, long long sum, int xl){
//	cout << sr << ' ' << sum << ' ' << xl << '\n';
	vis[sr] = 1;
	if(sr == e){
		ans = min(ans, sum + t[xl][sr]);
		vis[sr] = 0;
		return;
	}
	for(int i = 0; i < g[sr].size(); i ++){
		if(!vis[g[sr][i].v]) 
			dfs(g[sr][i].v, sum + (g[sr][i].h != xl) * (t[g[sr][i].h][sr] + t[xl][sr]), g[sr][i].h);
	}
	vis[sr] = 0;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			if(j != 1) add(a[i][j-1], a[i][j], i);
		}
	}
	while(q --){
		memset(vis, 0, sizeof vis);
		cin >> s >> e;
		vis[s] = 1;
		for(int i = 0; i < g[s].size(); i ++){
			dfs(g[s][i].v, t[g[s][i].h][s], g[s][i].h);
		}
		cout << ans + (w[s] + w[e]) << '\n';
		ans = LLONG_MAX;
	}
	return 0;
}

