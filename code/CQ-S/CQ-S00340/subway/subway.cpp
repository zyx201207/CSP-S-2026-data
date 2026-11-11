#include<bits/stdc++.h>
#define fr first
#define sd second
using namespace std;
using ll=long long;
const int N=5e5+10,M=5e2+10;
ll c,n,m,d,q;
ll w[N];
vector<pair<ll,ll>> e[N],g[M];
ll ds[M][M];
bool vs[M];
void solve(){
	ll x,y,ans=1e18;
	cin>>x>>y;
	for(auto olo:e[x])for(auto lol:e[y]){
		ll u=olo.fr,w1=olo.sd,v=lol.fr,w2=lol.sd;
		ans=min(ans,ds[u][v]+w1+w2);
	}
	cout<<ans+w[x]+w[y]<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;cin>>k;
		while(k--){
			ll x,y;cin>>x>>y;
			e[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ds[i][j]=(i==j?0ll:(ll)1e18);
	for(int i=1;i<=m;i++){
		for(auto olo:e[i]){
			ll u=olo.fr,w1=olo.sd;
			for(auto lol:e[i]){
				ll v=lol.fr,w2=lol.sd;
				if(u==v)continue;
				ds[u][v]=ds[v][u]=min(ds[u][v],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&ds[i][j]!=1e18)g[i].push_back({j,ds[i][j]});
	for(int i=1;i<=n;i++){
		priority_queue<pair<ll,ll>>pq;
		for(auto olo:g[i]){
			ll v=olo.fr,w=olo.sd;
			pq.push({-w,v});
		}
		for(int j=1;j<=n;j++)vs[j]=0;
		while(!pq.empty()){
			ll u=pq.top().sd;pq.pop();
			if(vs[u])continue;
			vs[u]=1;
			for(auto olo:g[u]){
				ll v=olo.fr,w=olo.sd;
				if(ds[i][v]>ds[i][u]+w)ds[i][v]=ds[i][u]+w,pq.push({-ds[i][v],v});
			}
		}
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<ds[i][j]<<"\n";
	while(q--)solve();
	return 0;
}

