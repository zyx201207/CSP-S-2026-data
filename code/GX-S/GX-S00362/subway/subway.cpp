#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct side{
	int v,w,nxt = -1;
}e[2000005];
int head[1505],cnt = 0;
int dis[1505];
bool vis[1505];
priority_queue<pair<int,int>> q;
void add_edge(int u,int v,int w){
	e[++cnt] = {v,w,head[u]};
	head[u] = cnt;
}
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s] = 0;
	q.push({0,s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if (!vis[u]){
			vis[u] = 1;
			for (int i = head[u];~i;i = e[i].nxt){
				int v = e[i].v;
				int w = e[i].w;
				if (dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					q.push({dis[v],v});
				}
			}
		}
	}
}
int c,n,m,d,q1;
int w[1505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q1;
	for (int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for (int i = 1;i<=n;i++){
		int k;
		cin >> k;
		for (int j = 1;j<=k;j++){
			int t1,t2;
			cin >> t1 >> t2;
			add_edge(i,t1+n,t2);
			add_edge(t1+n,i,t2);
		}
	}
	for (int i = 1;i<=q1;i++){
		int u1,v1;
		cin >> u1 >> v1;
		dij(u1+n);
		cout << dis[v1+n] + w[u1] + w[v1] << endl;
	}
	return 0;
}