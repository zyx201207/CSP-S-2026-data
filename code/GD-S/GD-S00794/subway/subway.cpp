#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=505,M=500005;
int n,m,d,q,f[N][N],a[M];
vector<pr>g[M];
signed main(){
#ifndef XYZ
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int u,v;
			cin>>u>>v;
			for(auto k:g[u]){
				f[i][k.fi]=min(f[i][k.fi],v+k.se);
				f[k.fi][i]=min(f[k.fi][i],v+k.se);
			}
			g[u].emplace_back(i,v);
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
		int x,y;
		cin>>x>>y;
		int r=0x3f3f3f3f3f3f3f3f;
		for(auto i:g[x]){
			for(auto j:g[y]){
				r=min(r,f[i.fi][j.fi]+a[x]+a[y]+i.se+j.se);
			}
		}
		cout<<r<<'\n';
	}
	return 0;
}

