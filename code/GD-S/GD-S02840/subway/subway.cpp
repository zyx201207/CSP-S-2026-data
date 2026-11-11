#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,M=5e5+5;
ll c,n,m,d,q,ans;
ll a[M];
ll dis[N][N],mnd[N][N];
vector<pair<ll,ll> > v[M];
inline void dijkstra(ll s){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<> > q;
	for(ll i=1;i<=n;i++)mnd[s][i]=2e18;
	q.emplace(0,s),mnd[s][s]=0;
	while(!q.empty()){
		auto [d,u]=q.top();
		q.pop();
		if(d>mnd[s][u])continue;
		for(ll i=1;i<=n;i++)if(mnd[s][i]>mnd[s][u]+dis[u][i])mnd[s][i]=mnd[s][u]+dis[u][i],q.emplace(mnd[s][i],i);
	}
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)if(i!=j)dis[i][j]=2e18; 
	for(ll i=1,k,x,t;i<=n;i++){
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++){
			scanf("%lld%lld",&x,&t);
			for(auto &[u,w]:v[x])dis[i][u]=dis[u][i]=min({dis[i][u],dis[u][i],t+w});
			v[x].push_back({i,t});
		}
	}for(ll i=1;i<=n;i++)dijkstra(i);
	for(ll i=1,u,w;i<=q;i++){
		scanf("%lld%lld",&u,&w),ans=2e18;
		for(auto &[o,p]:v[u])for(auto &[r,s]:v[w])ans=min(ans,p+s+mnd[o][r]+a[u]+a[w]);
		printf("%lld\n",ans);
	}return 0;
}

