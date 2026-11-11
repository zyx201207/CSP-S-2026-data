#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,M=5e2+10;
ll c,n,m,d,q;
ll ww[N],dis[M][M];
struct Edge{
	ll v;ll w;
};
vector<Edge>e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>ww[i];
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		for(ll j=1,x;j<=k;j++){
			ll t;
			cin>>x>>t;
			e[x].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)dis[i][j]=1e16;
		dis[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<e[i].size();j++){
			for(ll k=j+1;k<e[i].size();k++){
				ll u=e[i][j].v,v=e[i][k].v,w=e[i][j].w+e[i][k].w;
				if(dis[u][v]>w)dis[u][v]=dis[v][u]=w;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			for(ll k=i;k<=j;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
			dis[j][i]=dis[i][j];
		}
	}
	for(ll i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(auto k:e[x]){
			ll v=k.v,w=k.w;
			for(auto kk:e[y]){
				ll vv=kk.v,www=kk.w;
				if(dis[v][vv]<1e16)ans=min(ans,dis[v][vv]+w+www);
			}
		}
		ans+=ww[x]+ww[y];
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/

