#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500+12,M=5e5+12,INF=1e18+12;
ll c,n,m,d,q;
ll w[M];
unordered_set<ll>p[N];//lines's poll
unordered_map<ll,ll>lines[N];// a->t
unordered_set<ll>th[M];//through
ll cdis[N][N];//change dist
bitset<N>vis;
ll dis[N][N];
struct edge{
	ll to;//lines
	ll dist;
	friend bool operator<(const edge&i1,const edge&i2){
		return i1.dist>i2.dist;
	}
};
vector<edge>e[N];
void dijkstra(const ll s){
	fill(dis[s]+1,dis[s]+n+1,INF);
	dis[s][s]=0;
	vis.reset();
	priority_queue<edge>pq;
	pq.push({s,0});
	while(!pq.empty()){
		const ll u=pq.top().to;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(const edge&i:e[u]){
			const ll v=i.to;
			const ll w=dis[s][u]+i.dist;
			if(w<dis[s][v]){
				dis[s][v]=w;
				pq.push({v,w});
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	//cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i){
		scanf("%lld",&w[i]);
		//cin>>w[i];
	}
	for(ll i=1;i<=n;++i){
		ll k;
		//cin>>k;
		scanf("%lld",&k);
		while(k--){
			ll a,t;
			//cin>>a>>t;
			scanf("%lld%lld",&a,&t);
			p[i].insert(a);
			lines[i][a]=t;
			th[a].insert(i);
		}
	}
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j){
			if(i==j){
				cdis[i][j]=0;
				continue;
			}
			cdis[i][j]=INF;
			for(const ll k:p[i]){
				if(p[j].count(k)){
					cdis[i][j]=min(cdis[i][j],lines[i][k]+lines[j][k]);
				}
			}
		}
	}
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j){
			if(cdis[i][j]<INF){
				e[i].push_back({j,cdis[i][j]});
			}
		}
	}
	for(ll i=1;i<=n;++i){
		dijkstra(i);
	}
	while(q--){
		ll x,y;cin>>x>>y;
		ll ans=INF;
		for(const ll st:th[x]){
			for(const ll ed:th[y]){
//				cout<<"stdstsadt:"<<w[x]<<' '<<lines[st][x]<<' '<<dis[st][ed]<<' '<<lines[ed][y]<<' '<<w[y]<<'\n';
//				cout<<"sum:"<<w[x]+lines[st][x]+dis[st][ed]+lines[ed][y]+w[y]<<'\n';
				ans=min(ans,w[x]+lines[st][x]+dis[st][ed]+lines[ed][y]+w[y]);
			}
		}
		printf("%lld\n",ans);
//		cout<<ans<<'\n';
	}
	return 0;//HAPPY ENDING
}
