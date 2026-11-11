#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 505, M = 5e5 + 5;

int c, n, m, d, q, k[N];
ll w[M], dis[N][N], ans;
bool vis[N];

struct edge{
	int v;
	ll w;
};

vector<edge> g[M], g2[N + M];

struct tp{
	int u;
	ll dis;
};

struct cmp{
	bool operator()(const tp &i, const tp &j) const{
		return i.dis > j.dis;
	}
};

priority_queue<tp, vector<tp>, cmp> pq;

void dij(int start_){
	for(int i = 1; i <= n; i++){
		dis[start_ - m][i] = 1e18;
		vis[i] = 0;
	}
	dis[start_ - m][start_ - m] = 0;
	pq.push({start_, 0});
	while(!pq.empty()){
		tp item = pq.top();
		pq.pop();
		if(vis[item.u - m]){
			continue;
		}
		vis[item.u - m] = 1;
		for(edge it : g2[item.u]){
			if(dis[start_ - m][it.v - m] > item.dis + it.w){
				dis[start_ - m][it.v - m] = item.dis + it.w;
				pq.push({it.v, dis[start_ - m][it.v - m]});
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int id;
			ll w;
			cin >> id >> w;
			g[id].push_back({i + m, w});
//			cout << id << ' ' << i + m << '\n';
		}
	}
	for(int i = 1; i <= m; i++){
		int len = g[i].size();
		for(int j = 0; j < len - 1; j++){
			for(int l = j + 1; l < len; l++){
//				cout << j << ' ' << l << ' ' << g[i][j].v << ' ' << g[i][l].v << ' ' << g[i][j].w << ' ' << g[i][l].w << '\n';
				g2[g[i][j].v].push_back({g[i][l].v, g[i][j].w + g[i][l].w});
				g2[g[i][l].v].push_back({g[i][j].v, g[i][j].w + g[i][l].w});
			}
		}
	}
	for(int i = m + 1; i <= m + n; i++){
		dij(i);
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << dis[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	while(q--){
		int a, b;
		cin >> a >> b;
		ans = 1e18;
		for(edge it : g[a]){
			for(edge it2 : g[b]){
				ans = min(ans, dis[it.v - m][it2.v - m] + it.w + it2.w + w[a] + w[b]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
