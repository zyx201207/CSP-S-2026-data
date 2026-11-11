#include<bits/stdc++.h>
#define Is_inky_ya ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sofree freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
#define endl '\n'
using namespace std;
using lint = long long ;
using doubao = long double;
const lint N = 5e5+5;
lint c,n,m,d,q;
lint w[N],k[505],x[100005],y[100005],sum[N];
struct Edge{
	lint u,t;
};
vector<Edge> a[N];
vector<Edge> ar[N];
vector<pair<lint,lint>> g[N];
struct node{
	lint u,dis;
	inline bool operator<(const node& x)const{
		return dis>x.dis;
	} 
}; 
priority_queue<node> q1;
lint dis[2000005],vis[2000005];
inline void dijkstra(lint s){
	vis[s] = 0;
	dis[s] = 0;
	q1.push({s,0});
	while(!q1.empty()){
		auto u = q1.top().u;
		q1.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto i:g[u]){
			lint v = i.first;
			lint w = i.second;
			if(dis[v]>dis[u]+w){
				dis[v] = dis[u]+w;
				q1.push({v,dis[v]});
			}
		}
	}
}
int main(){
#ifndef AKIOI
	Is_inky_ya
#endif
	sofree
	cin>>c>>n>>m>>d>>q;
	if(c==0) c=1;
	while(c--){
		for(lint i=1;i<=n;i++){
			a[i].clear();
		}
		for(lint i=1;i<=m;i++){
			cin>>w[i];
			ar[i].clear();
		}
		memset(g,0,sizeof g);
		for(lint i=1;i<=n;i++){
			cin>>k[i];
			sum[i] = sum[i-1]+k[i];
			for(lint j=1;j<=k[i];j++){
				lint u,v;
				cin>>u>>v;
				a[i].push_back({u,v});
				ar[u].push_back({i,v});
			}
		}
		for(lint i=1;i<=n;i++){
			for(lint j=0;j<a[i].size()-1;j++){
				lint u = a[i][j].u;
				lint v = a[i][j+1].u;
				g[u+sum[i]].push_back({v+sum[i],0});
				g[v+sum[i]].push_back({u+sum[i],0});
			}
		}
		for(lint i=1;i<=m;i++){
			for(auto j:ar[i]){
				for(auto k:ar[i]){
					g[i+sum[j.u]].push_back({i+sum[k.u],j.t+k.t});
					g[i+sum[k.u]].push_back({i+sum[j.u],j.t+k.t});
				}
			}
		}
		memset(dis,0x3f,sizeof dis);
		for(lint i=1;i<=q;i++){
			cin>>x[i]>>y[i];
			lint ans = INT_MAX;
			for(auto j:ar[x[i]]){
				lint cnt = w[x[i]]+w[y[i]]+j.t;
				dijkstra(x[i]+sum[j.u]);
				for(auto k:ar[y[i]]){
					if(dis[y[i]+sum[k.u]]<=2000000000){
						ans = min(ans,cnt+dis[y[i]+sum[k.u]]+k.t);
					}
				}
				memset(dis,0x3f,sizeof dis);
			}
			cout<<ans<<endl;
		} 
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

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
