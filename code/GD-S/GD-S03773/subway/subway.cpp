#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 5.5e5 + 5;
int c,n,m,d,q;
int w[N],dis[515],f[505][505]; 
bool vis[515];
vector<PII> e[N],ne[N];
void dijkstra(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<PII,vector<PII>,greater<PII>> q;
	dis[st] = 0;
	q.push({0,st});
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto i:ne[u]){
			int v = i.first, w = i.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(f,0x3f,sizeof(f));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1,k;i <= n;i++){
		cin >> k;
		for(int j = 1,v,w;j <= k;j++){
			cin >> v >> w;
			//e[m+i].push_back({v,w});
			e[v].push_back({m+i,w});
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < e[i].size();j++){
			int u = e[i][j].first, w1 = e[i][j].second;
			for(int k = 0;k < e[i].size();k++){
				int v = e[i][k].first, w2 = e[i][k].second;
				f[u-m][v-m] = min(f[u-m][v-m],w1+w2);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(f[i][j] <= 1e18){
				ne[i].push_back({j,f[i][j]});
				ne[j].push_back({i,f[i][j]});
			}
		}
	}
	//dijkstra(1);
	int st,ed;
	while(q--){
		cin >> st >> ed;
		for(auto i:e[st]){
			int v = i.first, w = i.second;
			ne[n+1].push_back({v-m,w});
		}
		dijkstra(n+1);
		int RD = 1e18;
		for(auto i:e[ed]){
			int u = i.first, w = i.second;
			RD = min(RD,dis[u-m] + w);
		}
		cout << w[st] + RD + w[ed] << "\n";
		ne[n+1].clear();
	} 
	return 0;
} 
