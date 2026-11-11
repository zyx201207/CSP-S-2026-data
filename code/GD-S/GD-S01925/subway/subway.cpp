#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=505,M=5e5+5;
int c,n,m,d,q,k,a,x,y;
ll w[M],t,dist[N][N];

struct Node{
	int to;
	ll t;
};
vector<Node>f[N],g[M];

void init(){
	for(int u=1;u<=n;u++){
		for(Node node:f[u]){
			int id=node.to;
			ll x=node.t;
			for(Node node2:g[id]){
				int v=node2.to;
				ll y=node2.t;
				dist[u][v]=min(dist[u][v],x+y);
			}
		}
	}
}

void Floyd(){
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i!=j&&j!=k&&i!=k)
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i==j)dist[i][j]=0;
		else dist[i][j]=1e18;
	}
	
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			f[i].push_back({a,t});
			g[a].push_back({i,t});
		}
	}
	
	init();
	Floyd();
	
	while(q--){
		cin>>x>>y;
		ll ans=w[x]+w[y],res=1e18+7;
		for(Node u:g[x])
		for(Node v:g[y])
		res=min(res,u.t+v.t+dist[u.to][v.to]);
		if(res!=1e18+7)
		ans+=res;
		cout<<ans<<'\n';
	}
	
	return 0;
}
