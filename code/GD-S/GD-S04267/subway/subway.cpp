#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=550;
const ll M=500050;
const ll INF=0x3f3f3f3f3f3f3f3f;
vector<pii>sta[N];//当前地铁站属于的线路以及转线代价 
vector<pii>g[N];//第i条路线能够转到的路线以及转线代价 
ll tse[N];//站厅到站口的时间  
ll c,n,m,d,q;
priority_queue<pii,vector<pii>,greater<pii> >pq; 
ll dist[N];
bool vis[N];
ll dijkstra(ll st,ll en){//当前线路st到线路en的最短路 
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	pq.push({0,st});
	dist[st]=0;
	while(pq.size()){
		ll h=pq.top().second;
		pq.pop();
		if(vis[h])continue;
		vis[h]=1;
		for(pii edge:g[h]){
			ll to=edge.first,w=edge.second;
			if(dist[h]+w<=dist[to]&&vis[to]==0){
				dist[to]=dist[h]+w;
				pq.push({dist[to],to});
			}
		}
	}
	while(pq.size())pq.pop();
	return (dist[en]>=INF?-1:dist[en]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>tse[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			sta[x].push_back({i,y});
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<"\n";
//		for(pii e:sta[i]){
//			cout<<e.first<<","<<e.second<<"\n";
//		}
//	}
	for(ll i=1;i<=m;i++){//建图 
		for(pii e1:sta[i]){
			for(pii e2:sta[i]){
				ll u=e1.first,v=e2.first;
				ll w=e1.second+e2.second;
				if(u==v)continue;
				g[u].push_back({v,w});
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<"\n";
//		for(pii edge:g[i]){
//			cout<<edge.first<<","<<edge.second<<"\n";
//		}
//	}
	while(q--){
		ll st,en;
		cin>>st>>en;
		ll change_time=INF;//换long long注意 
		bool flag=0;
		//cout<<"\n";
		for(pii e1:sta[st]){
			for(pii e2:sta[en]){
				ll u=e1.first,v=e2.first;
				ll w=e1.second+e2.second;//注意算上起始点的站厅到站台的时间 
				//cout<<u<<","<<v<<","<<w<<","<<dijkstra(u,v)<<"\n";
				if(u==v){
					change_time=w;
					flag=1;
					break;
				}
				ll dij=dijkstra(v,u);
				if(dij==-1)continue;
				change_time=min(change_time,dij+w);
				//cout<<change_time<<"\n";
			}
			if(flag)break;
		}
		cout<<change_time+tse[st]+tse[en]<<"\n";
	}
	return 0;
}
