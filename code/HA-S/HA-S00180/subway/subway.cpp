#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>

ll ccc,n,m,D,Q;
ll w[510000];
vector <pi > g[510000];
vector <ll> gg[510];
ll f[510][510];
ll dis[510];

priority_queue<pi,vector<pi >,greater<pi > > q;

void dijsktra(ll s){
	for (int i=1;i<=n;i++) dis[i]=1e18;
	while (!q.empty()) q.pop();
	q.push({0,s});
	dis[s]=0;
	while (!q.empty()){
		pi xx=q.top();q.pop();
		ll u=xx.second;
		for (ll v:gg[u]){
			if (dis[v]>dis[u]+f[u][v]){
				dis[v]=dis[u]+f[u][v];
				q.push({dis[v],v});
			}
		}
	}
	for (int i=1;i<=n;i++){
		f[s][i]=dis[i];
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>ccc>>n>>m>>D>>Q;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for (int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for (int i=1;i<=m;i++){
		ll sz=g[i].size();
		for (int j=0;j<sz;j++){
			for (int k=j+1;k<sz;k++){
				ll u=g[i][j].first,v=g[i][k].first;
				ll ut=g[i][j].second,vt=g[i][k].second;
				if (f[u][v]==1e18){
					gg[u].push_back(v);
					gg[v].push_back(u);
				}
				f[u][v]=f[v][u]=min(f[u][v],ut+vt);
			}
		}
	}
	for (int i=1;i<=n;i++){
		dijsktra(i);
	}
	while (Q--){
		ll x,r;
		cin>>x>>r;
		ll ans=1e18;
		for (pi i:g[x]){
			for (pi j:g[r]){
				ll u=i.first,v=j.first;
				ll ut=i.second,vt=j.second;
				if (u==v){
					ans=min(ans,ut+vt);
				}else{
					ans=min(ans,f[u][v]+ut+vt);
				}
			}
		}
		ans+=w[x]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
