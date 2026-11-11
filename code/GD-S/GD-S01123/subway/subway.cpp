#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int inf=1e18; 
int c,n,m,d,q,w[N],f[1007][1007],t[N],b[N];

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=inf;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>t[j]>>b[j];
		for(int x=1;x<=k;x++){
			for(int y=x+1;y<=k;y++){
				int u=t[x],v=t[y];
				f[u][v]=min(f[u][v],b[x]+b[y]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<f[u][v]+w[u]+w[v]<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
	//cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
	return 0;
}
