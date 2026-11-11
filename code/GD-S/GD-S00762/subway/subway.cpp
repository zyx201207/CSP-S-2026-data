#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000008
#define INF 1e17
#define PII pair<int,int>
#define fir first
#define sec second
int c,n,m,d,q,st[N],tim[N],dist[N];
vector<PII > e[N];
void dijkstra(int s,int f){
	for(int i=1;i<=n+m;i++){
		st[i]=0;
		dist[i]=INF;
	}
	priority_queue<PII > q;
	q.push({0,s});
	dist[s]=0;
	while(q.size()){
		int u=q.top().sec;
		q.pop();
		st[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].fir;
			int w=e[u][i].sec;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if((v==f||e[v].size()>1)&&st[v]==0){
					q.push({-dist[v],v});
				}
			}
		}
	}
//	for(int i=1;i<=n*2+m;i++){
//		cout<<dist[i]<<' ';
//	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
//		int w;
		scanf("%lld",&tim[i]);
//		e[i].push_back({i+n,w});
//		e[i+n].push_back({i,w});
//		cout<<w<<' ';
	}
	for(int i=1;i<=m;i++){
		int u,w,k;
		scanf("%lld",&k);
		while(k--){
			scanf("%lld %lld",&u,&w);
			e[u].push_back({n+i,w});
			e[n+i].push_back({u,w});
		}
	}
//	for(int i=1;i<=n*2+m;i++){
//		cout<<i<<"  ";
//		for(int j=0;j<e[i].size();j++){
//			cout<<e[i][j].fir<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dijkstra(u,v);
		printf("%lld\n",dist[v]+tim[u]+tim[v]);
	}
	return 0;
}
