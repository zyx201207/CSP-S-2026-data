// GZ-S00298 游景智 
#include<bits/stdc++.h>
using namespace std;
// 把地铁站看作一个原点， O(mq)做法
// 可以把每个地铁站换乘总代价计算出来，连新边O(qd^2) 
// 枚举起点线路和到达终点的最后一个地铁线路，即可 
const int N = 500 + 10; 
const int M = 5e5 + 10; 
//vector<int> g[N]; 
typedef long long ll;
typedef pair<ll, ll > PII;
vector<PII> pos[M]; // 地铁站站点 first 地铁线路 second 换乘时间，注意是M
vector<PII> g[M]; // 地铁站互相换乘所用总时间 来+去 
ll w[M];
ll dis[N][N]; // 多源最短路 
int c, n, m, d, q;
const ll INF = 0x3f3f3f3f3f3f3f3f;
void dijkstra(int id){
	priority_queue<PII, vector<PII>, greater<PII> > hp;
	memset(dis[id], 0x3f, sizeof(dis[id]));
	dis[id][id] = 0ll;
	hp.push({0ll, id});
	while(hp.size() > 0){
		PII X = hp.top();
		hp.pop();
		ll x = X.second;
		for(int i = 0; i < (int)g[x].size(); i++){
			ll j = g[x][i].first, t = g[x][i].second;
			if(dis[id][j] > dis[id][x] + t){
				dis[id][j] = dis[id][x] + t;
				hp.push((PII){dis[id][j], j});
			}
		}
	} 
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			ll x, t;
			scanf("%lld%lld", &x, &t);
			pos[x].push_back((PII){i, t});
		}
	}
	for(int x = 1; x <= m; x++){
		for(int i = 0; i < (int)pos[x].size(); i ++){
			ll l = pos[x][i].first, lt = pos[x][i].second;
			for(int j = i + 1; j < (int)pos[x].size(); j++){
				ll r = pos[x][j].first, rt = pos[x][j].second;
				g[l].push_back({r, lt + rt});
				g[r].push_back({l, lt + rt});
			}
		}
	} 
	// 多源最短路 
	for(int i = 1; i <= n; i++){
		dijkstra(i);
	}
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = INF;
		for(int i = 0; i < (int)pos[x].size(); i++){
			ll l = pos[x][i].first, lt = pos[x][i].second;
			for(int j = 0; j < (int)pos[y].size(); j++){
				ll r = pos[y][j].first, rt = pos[y][j].second;
				if(l == r){
					ans = min(ans, w[x] + lt + rt + w[y]);
				}else{
					ans = min(ans, w[x] + lt + dis[l][r] + rt + w[y]);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
 


