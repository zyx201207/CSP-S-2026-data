#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3e6+10, M = 1010;
LL W[N], l[N];
LL e[N], w[N], ne[N], h[N], idx;
LL dist[M][M];
LL c, n, m, d, q;

void add(int a, int b, int c) {
	e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}

LL ANSWER(int x, int y) {
	LL DIST = 0x3f3f3f3f3f3f3f3f;
	
	for(int i=h[x]; i!=-1; i=ne[i]) {
		LL nu = e[i] - m;
		LL cst1 = w[i];
		for(int j=h[y]; j!=-1; j=ne[j]) {
			LL nv = e[j] - m;
			LL cst2 = w[j];
			DIST = min(DIST, dist[nu][nv] + cst1 + cst2);
		}
	}
	
	return (W[x] + W[y] + DIST);
}

void solve() {
	memset(h, -1, sizeof(h));
	idx = 0;
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) {
		cin >> W[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> l[i];
		for(int j=1; j<=2*l[i]; j+=2) {
			LL u = m+i;
			LL v, w;
			cin >> v >> w;
			add(u, v, w);
			add(v, u, w);
		}
	}
	
	memset(dist, 0x3f, sizeof(dist));
	
	for(int i=1; i<=n; i++) {
		dist[i][i] = 0ll;
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=h[i]; j!=-1; j=ne[j]) {
			LL nu = e[j] - m;
			LL cst1 = w[j];
			for(int k=h[i]; k!=-1; k=ne[k]) {
				LL nv = e[k] - m;
				LL cst2 = w[k];
				dist[nu][nv] = dist[nv][nu] = min(dist[nu][nv], cst1+cst2);
			}
		}
	}
	
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			cout << dist[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	for(int i=1; i<=q; i++) {
		LL u, v;
		cin >> u >> v;
		cout << ANSWER(u, v) << "\n";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) {
		solve();
	}
	
	return 0;
} 
