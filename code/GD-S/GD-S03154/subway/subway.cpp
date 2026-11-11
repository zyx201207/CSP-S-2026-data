#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int x,w;
	bool operator > (const node &other) const{
		return w > other.w;
	}
};

const int inf = 1e18;
int c,n,m,d,q,goout[502],dis[505][505],edge[505][505];
vector<node> adj[500005],tree[505];

void Dijkstra(int s){
	int vis[505];
	priority_queue< node,vector<node>,greater<node> > pq;
	for(int i=1;i<=n;++i){
		vis[i] = 0;
		dis[s][i] = inf;
	}
	dis[s][s] = 0;
	pq.push({s,0});
	while(!pq.empty()){
		node now = pq.top();
//		cout<<now.x<<endl;
		pq.pop();
		if(vis[now.x]) continue;
		vis[now.x]=1;
		for(auto nxt:tree[now.x]){
			if(dis[s][nxt.x] > dis[s][now.x]+nxt.w){
				dis[s][nxt.x] = dis[s][now.x]+nxt.w;
			}
			pq.push({nxt.x,dis[s][nxt.x]});
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%lld",&goout[i]);
	}
	for(int i=1;i<=n;++i){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=n;++j){
			edge[i][j] = inf;
		}
		edge[i][i] = 0;
		for(int j=1;j<=k;++j){
			int x,w;
			scanf("%lld %lld",&x,&w);
			adj[x].push_back({i,w});
		}
	}
	for(int t=1;t<=m;++t){
		for(int i=0;i<adj[t].size();++i){
			for(int j=i+1;j<adj[t].size();++j){
				node ii = adj[t][i];
				node jj = adj[t][j];
				edge[ii.x][jj.x] = min(edge[ii.x][jj.x],ii.w+jj.w);
				edge[jj.x][ii.x] = min(edge[jj.x][ii.x],ii.w+jj.w);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			if(edge[i][j] != inf){
				tree[i].push_back({j,edge[i][j]});
				tree[j].push_back({i,edge[i][j]});
			}
		}
	}
	for(int i=1;i<=n;++i){
		Dijkstra(i);
	}
//	Dijkstra(1);
//	printf("%lld\n",dis[3][1]);
	for(int Q=1;Q<=q;++Q){
		int start,end;
		scanf("%lld %lld",&start,&end);
		int ans=inf;
		for(auto i:adj[start]){
			for(auto j:adj[end]){
				int tot=goout[start]+goout[end]+i.w+j.w+dis[i.x][j.x];
				ans = min(ans,tot);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
