#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q,nodecnt=0;
vector<pair<ll,ll>> tx[550010];
ll w[550010];

ll mndis[510][510];
ll dis[510][510];
ll vis[510];
void dij(int s){
	for(int i=1;i<=n;++i){
		vis[i]=0;
		dis[s][i]=1e18;
	}
	dis[s][s]=0;
	for(int i=1;i<=n-1;++i){
		ll mn=1e18;
		int id=-1;
		for(int j=1;j<=n;++j){
			if(vis[j]) continue;
			if(dis[s][j]<mn){
				mn=dis[s][j];
				id=j;
			}
		}
		for(int j=1;j<=n;++j){
			if(mndis[id][j]!=1e18){
				dis[s][j]=min(dis[s][j],dis[s][id]+mndis[id][j]);
			}
		}
		vis[id]=1;
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	nodecnt=n+m;
	for(int i=1;i<=m;++i){
		cin >> w[i];
	}
	for(int i=1;i<=n;++i){
		ll k;
		cin >> k;
		for(int j=1;j<=k;++j){
			ll a,t;
			cin >> a >> t;
			tx[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			mndis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;++i){
		if(tx[i].size()<2) continue;
		for(int j=0;j<(int)(tx[i].size());++j){
			for(int k=j+1;k<(int)(tx[i].size());++k){
				int u=tx[i][j].first;
				int v=tx[i][k].first;
				mndis[u][v]=min(mndis[u][v],tx[i][j].second+tx[i][k].second);
				mndis[v][u]=min(mndis[v][u],tx[i][j].second+tx[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;++i){
		dij(i);
	}
	while(q-->0){
		int x,y;
		cin >> x >> y;
		ll ans=w[x]+w[y],tmp=1e18;
		for(pair<ll,ll> i:tx[x]){
			for(pair<ll,ll> j:tx[y]){
				ll u=i.first,v=j.first;
				tmp=min(tmp,dis[u][v]+i.second+j.second);
			}
		}
		ans+=tmp;
		cout << ans << '\n';
	}
	return 0;
}
// final ver.
