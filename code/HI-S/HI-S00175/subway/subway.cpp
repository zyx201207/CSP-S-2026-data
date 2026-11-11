#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=5e5;
int c,n,m,d,q;
ll w[N+5],dis[N+505];
int k[505],a[505][505];
vector<pair<int,ll> > edge[N+505];
bool vis[N+505];
ll spfa(int src,int tar){
	for(int i=1;i<=n+m;i++){
		dis[i]=INF;
	}
	queue<int> q;
	dis[src]=0;
	vis[src]=1;
	q.push(src);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].first;
			ll t=edge[u][i].second;
			if(dis[v]>dis[u]+t){
				dis[v]=dis[u]+t;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[tar];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		for(int j=1;j<=k[i];j++){
			int v;ll t;
			scanf("%d%lld",&v,&t);
			a[i][j]=v;
			edge[v].push_back(make_pair(i+m,t));
			edge[i+m].push_back(make_pair(v,t));
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",spfa(x,y)+w[x]+w[y]);
	}
	return 0;
}
