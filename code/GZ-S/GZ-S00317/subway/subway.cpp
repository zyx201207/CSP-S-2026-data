//GZ-S00317
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define eb emplace_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mkp make_pair
random_device rnd;
mt19937 rd(rnd());
const ll N=509,M=5e5+9,INF=0x3f3f3f3f3f3f3f;
ll c,n,m,d,q,w[M],k[N],dis[N][N];
vector<pll> G[M];
inline void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll a,t;
			cin>>a>>t;
			G[a].eb(mkp(i,t));
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto j:G[i]){
			for(auto k:G[i]){
				if(j.fi>=k.fi) continue; 
				dis[j.fi][k.fi]=min(dis[j.fi][k.fi],j.se+k.se);
				dis[k.fi][j.fi]=min(dis[k.fi][j.fi],j.se+k.se);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y,ans=INF;
		cin>>x>>y;
		for(auto i:G[x]){
			for(auto j:G[y]){
				ans=min(ans,dis[i.fi][j.fi]+i.se+j.se);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

