#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
struct edge{
	ll to,x;
};
ll w[505050],dist[505][505];
vector<edge> g[505050];
void dijkstra(ll n,ll s,ll m){
	for(int i=1;i<=n;i++){
		dist[s][i]=inf;
	}
	dist[s][s]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second,ud=pq.top().first;
		pq.pop();
		if(dist[s][u]!=ud) continue;
		for(edge e:g[u]){
			if(dist[s][u]+e.x<dist[s][e.to]){
				dist[s][e.to]=dist[s][u]+e.x;
				pq.push({dist[s][e.to],e.to});
				
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			ll a,t;
			scanf("%lld %lld",&a,&t);
			//if(a>i+m) throw 666;
			g[i+m/*Õ¾Ì¨*/].push_back({a/*Õ¾Ìü*/,t});
			g[a/*Õ¾Ìü*/].push_back({i+m/*Õ¾Ì¨*/,t});
		}
	}
	for(int i=1;i<=m;i++) dijkstra(m+n,i,m);
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			printf("#%d ",dist[i][j]);
		}
		putchar('\n');
	}
	*/
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%lld\n",dist[x][y]+w[x]+w[y]);
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
