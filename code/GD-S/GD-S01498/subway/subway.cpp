#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int n,m,d,q,a[M];
vector<pair<int,int>> f[M];
int e[N][N],dis[N][N];
void sol(){
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			f[v].push_back({i,w});
		}
	}
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)f[i].size();j++){
			for(int k=j+1;k<(int)f[i].size();k++){
				auto [u,w1]=f[i][j];
				auto [v,w2]=f[i][k];
				e[u][v]=min(e[u][v],w1+w2);
				e[v][u]=min(e[v][u],w1+w2);
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
//	cerr<<"dis:\n";
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int vis[N]{};
		for(int l=1;l<=n;l++){
			int u=0;
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(u==0||dis[i][u]>dis[i][j]){
					u=j;
				}
			}
			vis[u]=1;
			for(int v=1;v<=n;v++){
				if(dis[i][v]>dis[i][u]+e[u][v]){
					dis[i][v]=dis[i][u]+e[u][v];
				}
			}
		}
/*		for(int j=1;j<=n;j++){
			cerr<<dis[i][j]<<" ";
		}
		cerr<<"\n";*/
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18,cost1=a[x]+a[y];
		for(auto [u,w1]:f[x]){
			for(auto [v,w2]:f[y]){
				int cost2=w1+w2;
				ans=min(ans,cost1+cost2+dis[u][v]);
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int ct=1;
	while(ct--){
		sol();
	}
}
