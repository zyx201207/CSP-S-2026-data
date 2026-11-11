#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll c,n,m,d,q;
ll num[N];
vector<ll> way[N];
vector<pair<ll,ll>> hav[N];
ll f[600][600];
void solve(ll x,ll y){
	ll ans=1e18; 
	for(ll i=0;i<hav[x].size();i++){
		ll u=hav[x][i].first,w1=hav[x][i].second;
		for(ll j=0;j<hav[y].size();j++){
			ll v=hav[y][j].first,w2=hav[y][j].second;
			ans=min(ans,f[u][v]+w1+w2);
		}
	}
	ans+=num[x]+num[y];
	cout<<ans<<'\n';
	return;
}
void init(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j)f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<hav[i].size();j++){
			ll u=hav[i][j].first,w1=hav[i][j].second;
			for(ll k=0;k<hav[i].size();k++){
				ll v=hav[i][k].first,w2=hav[i][k].second;
				f[u][v]=min(f[u][v],w1+w2);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>num[i];
	}
	for(ll i=1;i<=n;i++){
		ll k,v,w;
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>v>>w;
			way[i].push_back(v);
			hav[v].push_back({i,w});
		}
	}	
	init();
	ll x,y;
	for(ll i=1;i<=q;i++){
		cin>>x>>y;
		solve(x,y);
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

32
17

*/
