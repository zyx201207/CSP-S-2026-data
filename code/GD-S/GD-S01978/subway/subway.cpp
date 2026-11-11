#include<bits/stdc++.h>
#define ll long long
#define M 500010
#define D 30
#define N 510
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const ll inf=1000000000000ll;
int c,n,m,d,q,w[M];
ll f[N][N];
vector<pii> a[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to,va;cin>>to>>va;
			a[to].push_back({i,va});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) f[i][j]=inf;
		}
	} 
	for(int i=1;i<=m;i++){
		int len=a[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				pii u=a[i][j],v=a[i][k];
				f[v.fi][u.fi]=f[u.fi][v.fi]=u.se+v.se;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			if(j==k) continue;
			for(int i=1;i<=n;i++){
				if(i==k||i==j) continue;
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int lnu=a[u].size(),lnv=a[v].size();
		ll ans=inf;
		for(int i=0;i<lnu;i++){
			for(int j=0;j<lnv;j++){
				pii nu=a[u][i],nv=a[v][j];
				ll now=f[nu.fi][nv.fi]+nu.se+nv.se+w[u]+w[v];
				ans=min(ans,now);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
//	for(int i=1;i<=M-10;i++){
//		for(int j=1;j<=D-10;j++){
//			a[i][j]=i*j;
//		}
//	}
//	while(1){
//		int x,y;cin>>x>>y;
//		cout<<a[x][y]<<endl;
//	}
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
