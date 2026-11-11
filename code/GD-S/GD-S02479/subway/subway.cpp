#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 506, maxm = 5e5 + 5;
struct edge{
	int v, w;
	bool operator < (const edge &W) const{
		return w < W.w;
	}
};
struct sta{
	int mtr, tim;
};
int c, n, m, d, q;
int w[maxm];
bool vis[maxn];
vector<sta> interchange[maxm];//换乘情况 
vector<edge> rk[maxn];//用于跑最短路 
int dis[maxn];
bool vvis[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k, a, t;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a >> t;
			if(vis[a]){
				for(auto it : interchange[a]){
					//线路间建边 
					rk[i].push_back({it.mtr, t + it.tim});
					rk[it.mtr].push_back({i, t + it.tim});
				}
			} 
			vis[a] = true;
			interchange[a].push_back({i, t});
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		//线路与地铁口建边 
		for(auto it : interchange[x]){
			rk[x].push_back({it.mtr, w[x] + it.tim});
			rk[it.mtr].push_back({x, w[x] + it.tim});
		}
		for(auto it : interchange[y]){
			rk[it.mtr].push_back({y, w[y] + it.tim});
			rk[y].push_back({it.mtr, w[y] + it.tim});
		}
		//Dijkstra - 优先队列+出队标记 
		memset(dis, 0x3f, sizeof dis);
		memset(vvis, 0, sizeof vis);
		priority_queue<edge> q;
		q.push({x, 0});
		dis[x] = 0;
		while(!q.empty()){
			edge cur = q.top();
			q.pop();
			if(vvis[cur.v]) continue;
			vvis[cur.v] = true;
			for(auto it : rk[cur.v]){
				if(dis[it.v] > dis[cur.v] + it.w){
					dis[it.v] = dis[cur.v] + it.w;
					q.push({it.v, it.w});
				} 
			}
		}
		//删除刚刚添加的边
		for(auto it : interchange[x]){
			rk[x].pop_back();
			rk[it.mtr].pop_back();
		}
		for(auto it : interchange[y]){
			rk[it.mtr].pop_back();
			rk[y].pop_back();
		}
		cout << dis[y] << "\n";
	}
	return 0;
}

