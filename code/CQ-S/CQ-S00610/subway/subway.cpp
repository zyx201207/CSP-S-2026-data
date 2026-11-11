#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define fi first
#define se second
#define ll long long
using namespace std;
const ll N=5e5+5;
ll c,n,m,d,q,s,en,ans;
ll w[N],k[N],a[N],t[N],dist[N],vis[N];
vector<pii> e[N];
void dij(){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,s});
	memset(dist,127,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	while(!q.empty()){
		ll x=q.top().se;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(ll i=0;i<(ll)e[x].size();i++){
			ll u=e[x][i].fi,v=e[x][i].se;
			if(dist[x]+v<dist[u]){
				dist[u]=dist[x]+v;
				q.push({dist[u],u});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(ll j=1;j<=k;j++){
			for(ll l=j+1;l<=k;l++){
				e[a[j]].push_back({a[l],t[l]+t[j]});
				e[a[l]].push_back({a[j],t[l]+t[j]});
			}
		}
	}
	while(q--){
		ans=0;
		cin>>s>>en;
		ans+=w[s]+w[en];
		dij();
		cout<<ans+dist[en]<<'\n';
	}
	return 0;
}
