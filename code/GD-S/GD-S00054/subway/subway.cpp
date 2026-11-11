#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll> 
#define mp make_pair
using namespace std;
const ll maxn=505;
const ll maxm=5e5+5;
const ll inf=1e17+5;
ll c,n,m,d,q,w[maxm];
ll dis[maxn][maxn];
vector<pi> a[maxm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin >>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin >>k;
		for(ll j=1;j<=k;j++){
			ll u,ww;
			cin >>u>>ww;
			a[u].push_back({i,ww});
		}
	}
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=n;j++) dis[i][j]=inf;
	for(ll i=1;i<=n;i++) dis[i][i]=0;
	for(ll i=1;i<=m;i++){
		ll len=a[i].size();
		for(ll p=0;p<len;p++)
		for(ll q=p+1;q<len;q++){
			pi tmpx=a[i][p],tmpy=a[i][q];
			ll u=tmpx.first,v=tmpy.first;
			ll w=tmpx.second+tmpy.second;
			dis[u][v]=min(dis[u][v],w);
			dis[v][u]=min(dis[v][u],w);
		} 
	}
	for(ll k=1;k<=n;k++)
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=n;j++){
		dis[i][j]=min(dis[i][j],
			dis[i][k]+dis[k][j]); 
	}
	while(q--){
		ll x,y;
		cin >>x>>y;
		ll ans=inf;
		ll len1=a[x].size(),len2=a[y].size();
		for(ll i=0;i<len1;i++)
		for(ll j=0;j<len2;j++){
			pi tmpx=a[x][i],tmpy=a[y][j];
			ll u=tmpx.first,v=tmpy.first;
			ll w=tmpx.second+tmpy.second;
			ans=min(ans,dis[u][v]+w);
		}
		cout <<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
