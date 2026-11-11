#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5000;
ll dis[N + 1];
int nxt[N + 1];
int dist[N + 1][N + 1];

int n;
ll d;

int get_dist(int x, int y){
	int res = 0;
	while (x != y){
		if (nxt[x] == 0) return INT_MAX;
		x = min(nxt[x], y);
		res++;
	}
	return res;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	scanf("%d %d", &c, &t);
	while (t--){
		scanf("%d %lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", &dis[i]);
		nxt[n] = 0;
		for (int i = 1; i <= n - 1; i++) {
			nxt[i] = upper_bound(dis + i + 1, dis + n + 1, dis[i] + d) - dis - 1;
			if (nxt[i] == i) nxt[i] = 0;
//			cout << "i=" << i << "  nxt[" << i << "]=" << nxt[i] << '\n'; 
		}
		int res = 0;
		for (int u = 1; u <= n; u++){
			for (int v = 1; v <= n; v++){
				dist[u][v] = INT_MAX;
			}
		}
		for (int u = 1; u <= n; u++){
			dist[u][u] = 0;
			for (int v = u + 1; v <= n; v++){
				dist[u][v] = get_dist(u, v);
//				cout << "u=" << u << "  v=" << v << "  dist[" << u << "][" << v << "]=" << dist[u][v] << '\n';
			}
		}
		
		for (int u = 1; u <= n; u++){
			for (int v = u + 1; v <= n; v++){
				int cnt = 0, d = dist[u][v];
				if (d == INT_MAX) continue;
				
				int x = u, y = v;
				while (x != y){
					int nt = min(nxt[x], y);
					for (int k = x + 1; k < nt; k++){
						if (dist[u][k] != INT_MAX && dist[k][v] != INT_MAX && dist[u][k] + dist[k][v] == d) cnt++;
					}
					x = nt;
				}
				if (cnt == 1) res++;
			}
		}
		
		printf("%d\n", res);
	}
	
	return 0;
}
