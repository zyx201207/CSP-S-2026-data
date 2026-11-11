#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long INF=4e18;
int c,n,m,d,q,w[M];
long long dis[N][N];
vector<int>vt[M];
map<int,long long>mp[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	int k,a,t;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			mp[i][a]=t;
			vt[a].push_back(i);
		}
	} 
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j) dis[i][j]=INF;
	}
	for(int i=1;i<=m;++i){
		for(int u:vt[i]){
			for(int v:vt[i]){
				if(u==v) dis[u][v]=dis[v][u]=0;
				dis[u][v]=dis[v][u]=min(dis[u][v],mp[u][i]+mp[v][i]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(dis[i][k]==INF||dis[k][j]==INF) continue;
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int u,v;
	long long sum,ans;
	for(int i=1;i<=q;++i){
		cin>>u>>v;
		sum=INF;
		ans=(long long)w[u]+(long long)w[v];
		for(int x:vt[u]){
			for(int y:vt[v]){
				sum=min(sum,dis[x][y]+mp[x][u]+mp[y][v]);
			}
		}
		cout<<ans+sum<<'\n';
	}
	return 0;
} 
