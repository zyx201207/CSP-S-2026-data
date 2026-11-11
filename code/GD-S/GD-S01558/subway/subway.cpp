#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=2e18;
const ll maxn=5e2+5;
const ll maxm=5e5+5;
ll c,n,m,d,q;
ll w[maxm];
ll k[maxn];
vector<ll> a[maxn],t[maxn];
vector<pair<ll,ll>> subs[maxm];
long long dis[maxn][maxn]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll A,T;cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			subs[A].push_back({i,T});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(ll i=1;i<=n;i++)dis[i][i]=0;
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<subs[i].size()-1;j++){
			for(ll k=j+1;k<subs[i].size();k++){
				ll u=subs[i][j].first,v=subs[i][k].first;
				ll ut=subs[i][j].second,vt=subs[i][k].second;
				dis[u][v]=min(dis[u][v],ut+vt);dis[v][u]=dis[u][v];
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		long long ans=inf;
		for(ll i=0;i<subs[x].size();i++){
			for(ll j=0;j<subs[y].size();j++){
				ll u=subs[x][i].first,v=subs[y][j].first;
				ll ut=subs[x][i].second,vt=subs[y][j].second;
				ans=min(ans,ut+vt+dis[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
