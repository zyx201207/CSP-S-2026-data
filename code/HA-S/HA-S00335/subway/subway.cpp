#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll,int>
using namespace std;
const int N=5e5+10;
const ll INF=1e18;
int c,n,m,d,q;
ll t1[N],dist[N];
vector<pi> g[N];
pi tmp[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&t1[i]);	
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int v; ll w;
			scanf("%d%lld",&v,&w);
			tmp[j]={w,v};
			for(int l=1;l<j;l++){
				int u=tmp[l].second;
				ll w1=tmp[l].first;
				g[u].push_back({w+w1,v});
				g[v].push_back({w+w1,u});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		priority_queue<pi,vector<pi>,greater<pi> > pq;
		for(int j=1;j<=m;j++){
			dist[j]=INF;
		}
		dist[x]=0;
		pq.push({0,x});
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();
			ll len=pq.top().first;
			for(int j=0;j<g[u].size();j++){
				int v=g[u][j].second;
				ll w=g[u][j].first;
				if(dist[u]+w<dist[v]){
					dist[v]=dist[u]+w;
					pq.push({dist[v],v});
				}
			}
		}
		printf("%lld\n",dist[y]+t1[x]+t1[y]);
	}
	return 0;
} 
