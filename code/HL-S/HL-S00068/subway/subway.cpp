#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500;
const int M=1e3;
int inf=0x3f3f3f3f;
int c,n,m,d,q,a[N][M],t[N][M];
int w[N],vis[N],f[N],k[N];
struct node{
	int v,w;
	bool operator>(const node & other) const{
		return w<other.w;
	}
};
vector<node> g[N];
priority_queue<node,vector<node>,greater<node>> pq;
void dijkstra(int x,int y){
	memset(f,inf,sizeof f);
	pq.push({x,0}); f[x]=0;
	while(!pq.empty()){
		int u=pq.top().v; pq.pop();
		if(vis[u]) continue; vis[u]=1;
		for(auto v:g[u]){
			if(f[v.v]>=f[u]+v.w){
				f[v.v]=f[u]+v.w;
				pq.push({v.v,f[v.v]});
			}
		}
	}
	cout<<(f[y]+2)*t[1][1]<<'\n';
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[i].push_back({j,1});
			g[j].push_back({i,1});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x,y);
	}
	return 0;
}

