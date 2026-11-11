#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pr; 
ll c,n,m,d,q;//n线路 m站数 q出行计划数 
ll w[500010],dis[500010][5],vis[500010][5];//1:站厅 0:线路 
vector<Pr> lineg[510],stag[500010];
void init(){
	for(ll i=1;i<=m;i++) dis[i][0]=dis[i][1]=LONG_LONG_MAX,vis[i][0]=vis[i][1]=0;
	return;
}
struct Point{
	ll dist,u,op;
	bool operator<(Point b)const{
		return dist<b.dist;
	}
};
void Dijkstra(ll st){
	init();
	priority_queue<Point> q;
	dis[st][1]=0;q.push({0,st,1});
	while(!q.empty()){
		Point now=q.top();
		ll dist=now.dist,u=now.u,op=now.op;
		q.pop();
		if(vis[u][op]) continue;
		if(op==1){
			for(auto i:stag[u]){
				ll v=i.first,val=i.second;
				if(dist+val<dis[v][0]&&!vis[v][0]){
					dis[v][0]=dist+val;
					q.push({dis[v][0],v,0});
				}
			}
		}else{
			for(auto i:lineg[u]){
				ll v=i.first,val=i.second;
				if(dist+val<dis[v][1]&&!vis[v][1]){
					dis[v][1]=dist+val;
					q.push({dis[v][1],v,1});
				}
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//c & d useless
	for(ll i=1;i<=m;i++) cin>>w[i];//地铁口 i costs w[i]
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;cin>>x>>y;
			lineg[i].push_back({x,y});//Line i passes Station x costs y
			stag[x].push_back({i,y});
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;cin>>x>>y;
		Dijkstra(x);
		cout<<dis[y][1]+w[x]+w[y]<<'\n';
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
*/
