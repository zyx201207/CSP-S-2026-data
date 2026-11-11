#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int v,w;
	operator <(const edge &o)const{
		return w > o.w;
	}
};
int dis[500010];
bool vis[500010];
int w[500010];
vector<edge> adj[500010];
vector<edge> l[500];
void dij(int st,int en){
	priority_queue<edge> q;
	dis[st] = 0;
	q.push({st,0});
	while(!q.empty()){
		int u = q.top().v;
		q.pop();
		if(vis[u]) continue;
		if(u == en)break;
		vis[u] = true;
		for(auto x : adj[u]){
			int v = x.v;
			int w = x.w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			int v,w;
			cin >> v >> w;
			l[i].push_back({v,w});
		}
	}
	for(int i = 1;i <= n;i ++){
		int cnt = -1;
		for(auto x : l[i]){
			cnt++;
			int u = x.v;
			int w1 = x.w;
			for(int j = cnt+1;j < l[i].size();j++){
				int v = l[i][j].v;
				int w2 = l[i][j].w;
				adj[u].push_back({v,w1+w2});
				adj[v].push_back({u,w1+w2});
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		for(int i = 1;i <= m;i ++){
			dis[i] = 1e9;
			vis[i] = false;
		}
		dij(x,y);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
