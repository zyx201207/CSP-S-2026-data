#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+7;
int c,n,m,d,q;
ll w[N];
ll t[507][N];
int st[N],en[N];
int vis[N];
ll dis[N];
struct node{
	int v;
	ll w;
	bool operator < (const node x)const{
		return w > x.w;
	}
};

vector<node> G[N];

void dijkstra(int st){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<node> pq;
	pq.push({st,0});
	dis[st] = 0;
	while(pq.size()){
		auto t = pq.top();
		pq.pop();
		int u = t.v;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto it:G[u]){
			int v = it.v;
			ll w = it.w;
			if(dis[v] > dis[u]+w){
				dis[v] = dis[u]+w;
				if(!vis[v])
					pq.push({v,dis[v]});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k; cin >> k;
		for(int j = 1;j <= k;j++){
			int a,b; cin >> a;
			cin >> t[i][a];
			if(j != 1){
				G[a].push_back({b,t[i][a]+t[i][b]});
				G[b].push_back({a,t[i][a]+t[i][b]});
			}
			b = a;
		}
	}
	for(int i = 1;i <= m;i++){
		G[0].push_back({i,w[i]});
		G[i].push_back({m+1,w[i]});
	}
	for(int i = 1;i <= q;i++){
		cin >> st[i] >> en[i];
		dijkstra(st[i]);
		cout << dis[en[i]] << endl;
	}	
	return 0;
}
