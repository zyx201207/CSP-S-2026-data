#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;const int M=5e5+5,inf=1e18;
int c,n,m,cnt,q,a[M],k[M],x,y,ans,d[555][555],vis[555];
struct Node{int v,w;};bool operator<(Node n1,Node n2){return n1.w>n2.w;}
vector<Node>e[555],g[M];
void Kru(int s){
	for(int i=1;i<=n;i++)d[s][i]=inf,vis[i]=0;
	priority_queue<Node>q;q.push({s,d[s][s]=0});
	while(!q.empty()){int u=q.top().v;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(auto nd:e[u])if(d[s][nd.v]>d[s][u]+nd.w)q.push({nd.v,d[s][nd.v]=d[s][u]+nd.w});
	}
}
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>cnt>>q;
	for(int i=1;i<=m;cin>>a[i++]);
	for(int i=1;i<=n;i++){cin>>k[i];
		for(int j=1,u,w;j<=k[i];j++){
			cin>>u>>w;g[u].pb({i,w});
		}
	}
	for(int t=1;t<=m;t++)for(auto n1:g[t])for(auto n2:g[t])if(n1.v!=n2.v)
		e[n1.v].pb({n2.v,n1.w+n2.w}),e[n2.v].pb({n1.v,n1.w+n2.w});
	for(int i=1;i<=n;i++)Kru(i);
	while(q--){
		cin>>x>>y;ans=inf;
		for(auto n1:g[x])for(auto n2:g[y])
			ans=min(ans,n1.w+n2.w+d[n1.v][n2.v]);
		cout<<ans+a[x]+a[y]<<"\n";
	}return 0;
}
