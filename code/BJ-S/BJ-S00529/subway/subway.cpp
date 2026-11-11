#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int c, n, m, f, q;
ll w[500010];
struct info{
	int id; ll dist;
};
vector<info> l[510], s[500010];
ll dis[510][510];
unordered_map<int, ll> cost[510];

int main(){
#ifndef LOCAL_TEST
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> f >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		int k; cin >> k;
		while(k --){
			int x, d;
			cin >> x >> d;
			// l[i].push_back({x, d});
			s[x].push_back({i, d});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i ++) dis[i][i] = 0;
	for(int i = 1; i <= m; i ++){
		for(int j = 0; j < s[i].size() - 1; j ++){
			int u = s[i][j].id; ll du = s[i][j].dist;
			for(int k = j + 1; k < s[i].size(); k ++){
				int v = s[i][k].id; ll dv = s[i][k].dist;
				dis[u][v] = dis[v][u] = min(dis[u][v], du + dv);
			}
		}
	}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			if(s[j].size() <= 5) continue;
			cost[i][j] = LLONG_MAX;
			for(int k = 0; k < s[j].size(); k ++){
				int lk = s[j][k].id; ll dk = s[j][k].dist;
				cost[i][j] = min(cost[i][j], dis[i][lk] + dk);
			}
		}
	}
	
	while(q --){
		int u, v;
		cin >> u >> v;
		ll ans = LLONG_MAX;
		for(int j = 0; j < s[u].size(); j ++){
			int lj = s[u][j].id; ll dj = s[u][j].dist;
			if(s[v].size() > 5){ ans = min(ans, dj + cost[lj][v]); continue; }
			for(int k = 0; k < s[v].size(); k ++){
				int lk = s[v][k].id; ll dk = s[v][k].dist;
				ans = min(ans, dj + dis[lj][lk] + dk);
			}
		}
		cout << w[u] + ans + w[v] << endl;
	}
}