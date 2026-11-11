#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=510,M=5e5+50;
const ll inf=2e16;
int c,n,m,d,q;
ll w[M];
int k[N];
vector<pair<int,ll>> T[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,w;
			cin>>x>>w;
			T[x].emplace_back(i,w);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int len=T[i].size();
		for(int j=0;j<len-1;j++){
			for(int k=j+1;k<len;k++){
				int u=T[i][j].fi,v=T[i][k].fi;
				if(dis[u][v]>T[i][j].se+T[i][k].se){
					dis[u][v]=T[i][j].se+T[i][k].se;
					dis[v][u]=T[i][j].se+T[i][k].se;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=inf;
		for(auto i:T[u]){
			for(auto j:T[v]) ans=min(ans,dis[i.fi][j.fi]+i.se+j.se);
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
