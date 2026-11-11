#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e2 + 5;
const int M = 5e5 + 5;
int c,n,m,d,q;
int w[M];
vector<pair<int,int> > p[N];
vector<pair<int,int> > pg[M];
vector<pair<int,int> > g[N];
int dist[N][N],vis[N][N];

void add(int u,int v,int w){
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			int aa,dd;
			scanf("%lld %lld",&aa,&dd);
			pg[aa].push_back({i,dd});
			p[i].push_back({aa,dd});
		}
	}
	for(int i = 1;i <= n;i ++){
		for(auto u1 : p[i]){
			for(auto u2 : pg[u1.first]){
				if(i == u2.first or vis[i][u2.first]) continue;
				add(i,u2.first,u1.second + u2.second);
				vis[i][u2.first] = 1;
				vis[u2.first][i] = 1;
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		memset(dist[i],0x3f,sizeof dist[i]);
		dist[i][i] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
		pq.push({0,i});
		while(pq.size()){
			auto cur = pq.top();
			int u = cur.second;
			int st = cur.first;
			pq.pop();
			if(st > dist[i][u]) continue;
			for(auto it : g[u]){
				int v = it.first;
				if(dist[i][u] + it.second < dist[i][v]){
					dist[i][v] = dist[i][u] + it.second;
					pq.push({dist[i][v],v});
				}
			}
		}
	}
	for(int ff = 1;ff <= q;ff ++){
		int u,v,ans = 1e18;
		cin >> u >> v;
		for(auto itu : pg[u]){
			for(auto itv : pg[v]){
				ans = min(ans,dist[itu.first][itv.first] + itu.second + itv.second + w[u] + w[v]);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
