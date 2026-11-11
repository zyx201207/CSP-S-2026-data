#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int N = 2e6 + 5;
int c, t, n, d, x[N];

//const int S = 1e3 + 5, MA = 1e18, M = 4e6 + 5;
//int dis[S][S];
//int f[S][S];
//int head[N], nxt[M], to[M], w[M], tot;
//inline void add(int x, int y, int val) {
//	nxt[tot] = head[x];
//	to[tot] = y;
//	w[tot] = val;
//	head[x] = tot ++;
//}
//int di[N], vis[N];
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
//inline int dij(int s) {
//	for(int i = 1; i <= n; ++ i) di[i] = MA;
//	for(int i = 1; i <= n; ++ i) vis[i] = 0;
//	while(!q.empty()) q.pop();
//	di[s] = 0;
//	q.push({0, s});
//	vis[s] = 1;
//	while(!q.empty()) {
//		while(!q.empty() && vis[q.top().second]) q.pop();
//		if(q.empty()) break;
//		int x = q.top().second;
//		vis[x] = 1;
//		q.pop();
//		for(int i = head[x]; ~i; i = nxt[i]) {
//			int y = to[i];
//			if(di[x] + w[i] < di[y]) {
//				di[y] = di[x] + w[i];
//				q.push({di[y], y});
//			}
//			if(di[x] + w[i] == di[y]) {
//				f[x][y] ++;
//			}
//		}
//	}
//	return di[n];
//}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = rd();
	t = rd();
	while(t --) {
		n = rd();
		d = rd();
//		for(int i = 1; i <= n; ++ i) {
//			to[i] = 0;
//		}
//		for(int i = 1; i <= n; ++ i) {
//			w[i] = 0;
//		}
//		tot = 0;
//		for(int i = 1; i <= n; ++ i) {
//			for(int j = 1; j <= n; ++ j) {
//				dis[i][j] =  MA;
//			}
//		}

		for(int i = 1; i <= n; ++ i) {
			x[i] = rd();
//			dis[i][i] = i;
		}
//		for(int i = 1; i <= n; ++ i) head[i] = -1;
//		for(int i = 1; i <= n; ++ i) {
//			for(int j = i + 1; j <= n; ++ j) {
//				if(x[j] - x[i] <= d) {
//					add(x[i], x[j], x[j] - x[i]);
//				}
//			}
//		}

//		for(int i = 1; i <= n; ++ i) {
//			cout << dij(i);
//		}
//		for(int k = 1; k <= n; ++ k) {
//			for(int i = 1; i <= n; ++ i) {
//				for(int j = 1; j <= n; ++ j) {
//					if(x[k] - x[i] <= d && x[j] - x[k] <= d) {
//						if(dis[x[x[i]]][x[j]] == dis[x[x[i]]][x[k]] + dis[x[k]][x[j]]) f[x[i]][x[j]] ++;
//						dis[x[i]][x[j]] = min(dis[x[i]][x[j]], dis[x[i]][x[x[k]]] + dis[x[x[k]]][x[j]]);
//					}
//				}
//			}
//		}



		int ans = 0;
//		for(int i = 1; i <= n; ++ i) {
//			for(int j = 1; j <= n; ++ j) {
//				if(f[x[i]][x[j]] == 2) ans ++;
//			}
//		}

//		int s = x[2] - x[1];
//		for(int i = 1; i <= n; ++ i) {
//			for(int j = i;j <= n;++ i) {
//				if(s * j <= d) {
//					ans =
//				}
//			}
//		}
		cout << ans << '\n';
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
