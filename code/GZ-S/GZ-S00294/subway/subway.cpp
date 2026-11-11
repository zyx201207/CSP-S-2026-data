//遵义市新蒲新区滨湖中学 金卓承 GZ-S00294
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,c,d,p,m;
const ll N=2e6;
vector<pll> G[N];
ll dis[N];
bool vis[N];
priority_queue<pll,vector<pll>,greater<pll> > q;
ll dijkstra(ll s,ll t){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		//cout<<u<<':';
		for(ll i=0;i<G[u].size();i++){
			ll v=G[u][i].second,w=G[u][i].first;
			//cout<<v<<' ';
			if(dis[u]+w<dis[v]){
				dis[v]=w+dis[u];
				q.push({dis[v],v});
			}
		}
		//cout<<endl;
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&p);
	//cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		int w;
		scanf("%lld ",&w);
		//cin>>w;
		G[i].push_back({w,i+m});
		G[i+m].push_back({w,i});
		//cout<<i<<' '<<i+m<<'\n';
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld ",&k);
		//cin>>k;
		int a,t;
		for(int j=1;j<=k;j++){
			scanf("%lld %lld ",&a,&t);
			//cin>>a>>t;
			G[i+2*m].push_back({t,a+m});
			G[a+m].push_back({t,i+2*m});
			//cout<<i+2*m<<' '<<a+m<<'\n';
		}
	}
//	scanf("%lld %lld %lld",&n,&m,&p);
//	for(int i=1;i<=m;i++){
//		int u,v,w;
//		cin>>u>>v>>w;
//		G[u].push_back({w,v});
//		G[v].push_back({w,u});
//	}
	while(p--){
		ll s,t;
		cin>>s>>t;
		ll ans=dijkstra(s,t);
		//cout<<ans<<'\n';
		printf("%lld\n",ans);
	}
	return 0;
}

