#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define ll long long
const int N=510;
const int M=5e5+10;
const ll INF=1e18;
int n,m,c,d,q;
ll w[M];
struct Edge{
	int to;
	ll w;
	void init(int u,ll w1){
		to=u;
		w=w1;
	}
}tmp;
vector<Edge> g[M];
ll dp[N][N];
int main(){
	FILE("subway"); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[i][j]=INF;
		dp[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u;
			ll t;
			cin>>u>>t;
			tmp.init(i,t);
			g[u].push_back(tmp);
		}
	}
	for(int k=1;k<=m;k++){
		int len=g[k].size();
		for(int i=0;i<len;i++){
			int u=g[k][i].to;
			ll w1=g[k][i].w;
			for(int j=0;j<len;j++){
				int v=g[k][j].to;
				ll w2=g[k][j].w;
				dp[u][v]=min(dp[u][v],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i].to,v=g[y][j].to;
				ll w1=g[x][i].w,w2=g[y][j].w;
				ans=min(ans,dp[u][v]+w1+w2);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
