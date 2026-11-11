#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500010],a[500010],t[500010];
long long dis[500010];
vector<pair<int,int> >adj[500010];
long long Dijkstra(int s,int t){
	for (int i = 1;i <= m;i++) dis[i] = 1e17;
	dis[s] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,s});
	while(!q.empty()){
		int u = q.top().second;
		if (dis[u] != q.top().first){
			q.pop();
			continue;
		}
		q.pop();
		for (int i = 0;i < (int)adj[u].size();i++){
			int v = adj[u][i].second,w = adj[u][i].first;
			if (dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[t] + w[s] + w[t];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int k,x,y;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	for (int i = 1;i <= n;i++){
		scanf("%d",&k);
		for (int j = 1;j <= k;j++){
			scanf("%d%d",&a[j],&t[j]);
			for (int l = j - 1;l >= 1;l--){
				adj[a[j]].push_back({t[j]+t[l],a[l]});
				adj[a[l]].push_back({t[j]+t[l],a[j]});
			}
		}
	}
	for (int i = 1;i <= q;i++){
		scanf("%d%d",&x,&y);
		printf("%lld\n",Dijkstra(x,y));
	}
	return 0;
}
