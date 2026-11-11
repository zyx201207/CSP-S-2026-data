#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[500010];
int dis[510][510],sum[510][500010];
vector<int>zd[500010];
vector<int>xl[510];
vector<int>g[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)w[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		for(int j=1;j<=m;j++){
			sum[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t2;
			cin>>x>>t2;
			xl[i].push_back(x);
			zd[x].push_back(i);
			sum[i][x]=t2;
		}	
	}
	for(int i=1;i<=n;i++){
		for(auto v:xl[i]){
			for(auto k:zd[v]){
				if(k==i)continue;
				if(sum[i][v]==inf||sum[k][v]==inf)continue;
				dis[i][k]=min(dis[i][k],sum[i][v]+sum[k][v]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]==inf)continue;
			for(int j=1;j<=n;j++){
				if(k==i||k==j||i==j)continue;
				if(dis[j][k]==inf)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(auto u:zd[x]){
			for(auto v:zd[y]){
				if(u==v)ans=min(ans,w[x]+w[y]+sum[u][x]+sum[v][y]);
				else ans=min(ans,w[x]+w[y]+dis[u][v]+sum[u][x]+sum[v][y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
