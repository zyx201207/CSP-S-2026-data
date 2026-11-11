#include <bits/stdc++.h>
#define MAXN 2000005
#define ll long long
using namespace std;
struct Edge{
	int v;
	ll w;
};
struct Point{
	int p;
	ll w;
};
struct cmp{
	bool operator ()(Point &a,Point &b){
		return a.w > b.w;
	}
};
vector<Edge> e[MAXN];
priority_queue<Point,vector<Point>,cmp> q;
ll c,d,n,m,r,dis[MAXN],dist[10005][10005];
bool vis[MAXN];
ll id(ll x,ll Floor){
	return x + m * Floor;
}
void addEdge(int u,int v,ll w){
	e[u].push_back((Edge){v,w});
	e[v].push_back((Edge){u,w});
}
inline void dijkstra(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s] = 0;
	q.push((Point){s,dis[s]});
	while(!q.empty()){
		Point head = q.top();
		q.pop();
		int now = head.p;
		if(vis[now]){
			if(now > m * (d + 1) && now <= m * (d + 2)){
				dist[now - m * (d + 1)][s] = dis[now];
				dist[s][now - m * (d + 1)] = dis[now];
			}
			continue;
		}
		vis[now] = true;
		for(int i = 0 ; i < e[now].size() ; i++){
			int v = e[now][i].v;
			ll w = e[now][i].w;
			if(dis[v] > dis[now] + w){
				dis[v] = dis[now] + w;
				q.push((Point){v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> r;
	for(int i = 1 ; i <= m ; i++){
		ll num;
		cin >> num;
		addEdge(id(i,0),id(i,d + 1),num);
	}
	for(int i = 1 ; i <= n ; i++){
		ll k;
		cin >> k;
		for(int j = 1 ; j <= k ; j++){
			ll pos,num;
			cin >> pos >> num;
			addEdge(id(pos,0),id(pos,i),num);
			addEdge(id(pos,i),id(i,d + 2),0);
		}
	}
	for(int i = 1 ; i <= r ; i++){
		ll xr,yr;
		cin >> xr >> yr;
		if(xr <= 10000 && yr <= 10000){
			if(dist[xr][yr] != 0){
				cout << dist[xr][yr] << "\n";
				continue;
			}
		}
		dijkstra(id(xr,d + 1));
		cout << dis[id(yr,d + 1)] << "\n";/*
		cout << "-----test-----\n";
		for(int i = 0 ; i <= d + 1 ; i++){
			for(int j = 1 ; j <= m ; j++){
				cout << id(j,i) << " " << dis[id(j,i)] << "\n";
			}
			cout << "next\n";
		}
		cout << "-----test-----\n";*/
	}
	return 0;
}
