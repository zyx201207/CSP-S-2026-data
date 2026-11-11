#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q,w[500001],f[501][501];
vector<pair<int,int>> g[500501];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1,u,w;j<=x;j++){
			cin>>u>>w;
			g[u].push_back({m+i,w});
			g[m+i].push_back({u,w});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto [u,x]:g[i]){
			for(auto [v,y]:g[i]){
				if(u!=v)f[u-m][v-m]=min(f[u-m][v-m],x+y);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int p,q,ans=1e18;
		cin>>p>>q;
		for(auto [u,x]:g[p]){
			for(auto [v,y]:g[q]){
				ans=min(ans,f[u-m][v-m]+x+y);
			}
		}
		cout<<ans+w[p]+w[q]<<"\n";
	}
}
