#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
#define N 500005
#define inf 0x3f3f3f3f
ll c,n,m,d,q, k[505], dis[2*N], w[N];
//vector<ll> a[505], t[505];
vector<pair<ll,ll> > e[2*N];
ll tot = 0;
bool vis[N];
ll dijkstra(int st, int ed){
	priority_queue<pair<ll,ll> > q;
	for(int i = 0;i <= tot;i++){
		dis[i] = inf;
	}
	dis[st] = 0;
	q.push({0, st});
	while(!q.empty()){
		int u = q.top().second, w1 = -q.top().first;
		q.pop();
		if(dis[u] < w1){
			continue;
		}
		for(auto v1:e[u]){
			ll v = v1.first, w = v1.second;
			if(dis[u]+w < dis[v]){
				//cout << "u:"<<u<<" v:"<<v<<"\n"; 
				dis[v] = dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
	/*for(int i = 1;i <= tot;i++){
		cout << dis[i] << " ";
	}
	cout << "\n";*/
	return dis[ed];
}
int main(){//, 地铁站厅1~m
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
		//e[i].push_back({i+m, w});
		//e[i+m].push_back({i, w});
	}
	tot = m+1;
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			ll a, t;
			cin >> a >> t;//a地铁站，t从站台到站厅 
			e[a].push_back({tot,t});
			e[tot].push_back({a,t});
		}
		tot++;
	}
	/*for(int i = 1;i <= tot;i++){
		cout <<i<<":";
		for(auto v:e[i])cout << v.second << " ";
		cout << "\n";
	}*/
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << dijkstra(x,y)+w[x]+w[y] << "\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
