#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
const int M = 5e5+5;
int c,n,m,d,q;
int v[M];

int k[N];
int a[M],t[M];
struct node{
	int a;
	int t;
};
vector<node>edgex[N];

struct node1{
	int k;
	int t;
};
vector<node1>edgeu[M];

int dist[5005][5005];
bool vis[10005];

struct Edge_dist{
	int u;
	int w;
	
	bool operator<(const Edge_dist & others) const {
		return w>others.w;
	}
};

void bfs(int st) {
	priority_queue<Edge_dist>q;
	dist[st][st]=0;
	memset(vis,false,sizeof(vis));
	
	q.push({st,0});
	
	while(!q.empty()) {
		Edge_dist tmp=q.top();
		q.pop();
		
		int u=tmp.u;
		int w=tmp.w;
		
		if(vis[u]) {
			continue;
		}
		vis[u]=true;
		
		for(node1 tmpk : edgeu[u]) {
			int tk=tmpk.k;
			int tt=tmpk.t;
			int nw=w+tt;
			
			for(node tmpv : edgex[tk]) {
				int v=tmpv.a;
				int nt=tmpv.t;
				int nnw=nw+nt;
				
				if(nnw<dist[st][v]) {
					dist[st][v]=nnw;
					q.push({v,nnw});
				}
			}
		}
	}
	
	return ;
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;i++) {
		scanf("%lld",&v[i]);
	}
	
	for(int i=1;i<=n;i++) {
		scanf("%lld",&k[i]);
		
		for(int j=1,ta,tt;j<=k[i];j++) {
			scanf("%lld%lld",&ta,&tt);
			edgex[i].push_back({ta,tt});
			edgeu[ta].push_back({i,tt});
		}
	}
	
	memset(dist,127,sizeof(dist));
	
	for(int i=1;i<=m;i++) {
		bfs(i);
	}
	
	while(q--) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",v[x]+v[y]+dist[x][y]);
	}
	return 0;
}
