#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	int t;
	ll w;
};
ll w[500005];
vector<edge> G[505005];
ll f[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qy;
	cin>>c>>n>>m>>d>>qy;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) f[i][j]=1e18;
			else f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			G[i+m].push_back({x,t});
			G[x].push_back({i+m,t});			
		}

	}
	for(int i=1;i<=n;i++){
		for(edge y:G[i+m]){
			for(edge yy:G[y.t]){
				if(yy.t!=(i+m)){
					f[i][yy.t-m]=min(f[i][yy.t-m],y.w+yy.w);
					f[yy.t-m][i]=f[i][yy.t-m];
				}
			}
		}		
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(k==i) continue;
			for(int j=1;j<=n;j++){
				if(k!=j&&k!=i&&i!=j){
					f[k][j]=min(f[k][j],f[k][i]+f[i][j]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<f[i][j]<<"NOS\n";
//		}
//	}
	while(qy--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(edge y:G[u]){
			for(edge yy:G[v]){
				if(y.t==yy.t){
					ans=y.w+yy.w+w[u]+w[v];
				}
				ans=min(ans,f[y.t-m][yy.t-m]+y.w+yy.w+w[u]+w[v]);
			}
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}
