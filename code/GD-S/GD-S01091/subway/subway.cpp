#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fi first
#define se second
bool bg;
const int maxm=5e5+5,maxn=505;
int in[maxm];
vector<pair<int,int> >g[maxm]; 
ll f[maxn][maxn];
bool vis[maxm];
int C,n,m,d,Q;
bool ed;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>in[i];
	for(int i=1;i<=n;i++){
		int len; cin>>len;
		for(int j=1;j<=len;j++){
			int u,v; cin>>u>>v;
			g[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:g[i]){
			for(auto v:g[i]){
				if(u.fi==v.fi) {
					f[u.fi][v.fi]=0;
					continue;
				}
				f[u.fi][v.fi]=min(f[u.fi][v.fi],(ll)u.se+v.se);
				f[v.fi][u.fi]=min(f[v.fi][u.fi],(ll)u.se+v.se);
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
	while(Q--){
		int u,v; cin>>u>>v;
		ll ans=1e18;
		for(auto x:g[u]){
			for(auto y:g[v]){
				ans=min(ans,f[x.fi][y.fi]+x.se+y.se);
			}
		}
		cout<<ans+in[u]+in[v]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
