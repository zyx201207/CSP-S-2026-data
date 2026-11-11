#include<bits/stdc++.h>
using namespace std;
const int N=505,M=2e5+5;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M],dis[N+M],vis[N+M];
vector<pair<int,int>> e[N+M];
void dij(int s){
	for(int i=1;i<=n+m;i++) dis[i]=INT_MAX,vis[i]=0;
	priority_queue<pair<int,int>> pq;
	dis[s]=0;
	pq.push({0,s});
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto x:e[u]){
			int v=x.first,w=x.second;
			if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push({-dis[v],v});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				e[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				e[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
