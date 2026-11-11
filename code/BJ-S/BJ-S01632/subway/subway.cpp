#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
typedef pair<ll,int> pli;
const int N = 505,M = 5e5+5;
int c,n,m,d,q;
ll W[M];
vector<pii> Adj[N],lines[M];
void addedge(int u,int v,int w){
	Adj[u].push_back(make_pair(v,w));
	Adj[v].push_back(make_pair(u,w));
}
ll dis[N][N]; bool vis[N][N];
priority_queue<pli,vector<pli>,greater<pli> > pq;
void dij(int s){
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;++i)dis[s][i] = 1e18,vis[s][i] = 0;
	dis[s][s] = 0ll;
	pq.push(make_pair(0ll,s));
	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		if(vis[s][u])continue;
		vis[s][u] = 1;
		int l = Adj[u].size();
		for(int i=0,v;i<l;++i){
			v = Adj[u][i].first;
			if(dis[s][v] > dis[s][u]+Adj[u][i].second){
				dis[s][v] = dis[s][u]+Adj[u][i].second;
				pq.push(make_pair(dis[s][v],v));
			}
		}
	}
}
ll ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%lld",&W[i]);
	for(int i=1,k,a,t;i<=n;++i){
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			scanf("%d%d",&a,&t);
			lines[a].push_back(make_pair(i,(ll)t));
		}
	}
	for(int i=1;i<=m;++i){
		int l = lines[i].size();
		for(int j=0;j<l;++j){
			for(int k=j+1;k<l;++k)addedge(lines[i][j].first,lines[i][k].first,lines[i][j].second+lines[i][k].second);
		}
	}
	for(int i=1;i<=n;++i)dij(i);
	for(int i=1,x,y;i<=q;++i){
		scanf("%d%d",&x,&y);
		int l1 = lines[x].size(),l2 = lines[y].size();
		ans = 2e18;
		for(int j=0;j<l1;++j){
			for(int k=0;k<l2;++k){
				ans = min(ans,W[x] + W[y] + lines[x][j].second + lines[y][k].second + dis[lines[x][j].first][lines[y][k].first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
