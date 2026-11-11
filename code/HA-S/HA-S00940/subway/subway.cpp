#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
namespace Callisto{
	const int N = 5e5+10, M = 500+10, INF = 1e9;
	int C, n, m, D, q, a[N];
	int hd[N], cnt;
	
	struct Edges{
		int u, v, w, nxt;
	}e[20*N];
	
	void addedge(int u, int v, int w){
		e[++cnt] = {u, v, w, hd[u]};
		hd[u] = cnt;
	}
	
	struct pii{
		int d, id;
		bool operator < (const pii &x) const{
			return d > x.d;
		}
	};
	
	int dis[N+M];
	
	int dij(int x, int y){
		priority_queue <pii> q;
		for(int i = 1; i <= m+n; i++) dis[i] = INF;
		q.push({0, x});
		dis[x] = 0;
		while(!q.empty()){
			int t = q.top().id, d = q.top().d;
			q.pop();
			if(t == y) return d;
			for(int i = hd[t]; i; i = e[i].nxt){
				int v = e[i].v;
				//cout << t << ':' << v << ' ' << dis[v] << ' ';
				if(dis[v] != INF) continue;
				if(dis[t]+e[i].w < dis[v]){
					dis[v] = dis[t]+e[i].w;
					q.push({dis[v], v});
				}
			}
		}
		return -1;
	}
	
	signed main(){
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(0), cout.tie(0);
		cin >> C >> n >> m >> D >> q;
		for(int i = 1; i <= m; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			for(int j = 1; j <= x; j++){
				int u, w;
				cin >> u >> w;
				addedge(u, i+m, w);
				addedge(i+m, u, w);
				//cout << u << ' ' << i+m << ' ' << w << endl;
			}
		}
		while(q--){
			int x, y;
			cin >> x >> y;
			cout << dij(x, y)+a[x]+a[y] << endl;
		}
		return 0;
	}
}

signed main(){
	Callisto::main();
	return 0;
}