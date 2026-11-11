#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=500005;
ll c,n,m,d,q,w[M],dis[505][505],sum;
vector<ll> K[M],t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++){
			ll A,T;
			scanf("%lld%lld",&A,&T);
			K[A].push_back(i);
			t[A].push_back(T);
		}
	}
	for(ll i=1;i<=m;i++){
		ll num=K[i].size();
		for(ll j=0;j<num;j++){
			for(ll k=0;k<num;k++){
				ll u=K[i][j],v=K[i][k];
				if(j==k) continue;
				dis[u][v]=min(dis[u][v],t[i][j]+t[i][k]);
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
		ll u,v,ans=1e18;
		scanf("%lld%lld",&u,&v);
		ll cnt1=K[u].size(),cnt2=K[v].size();
		for(ll i=0;i<cnt1;i++){
			for(ll j=0;j<cnt2;j++){
				ll aa=K[u][i],bb=K[v][j];
				ans=min(ans,t[u][i]+dis[aa][bb]+t[v][j]);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
