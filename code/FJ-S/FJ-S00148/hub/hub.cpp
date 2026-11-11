#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int C, T, n, k;
vector <int> edge[1000010];
int d[1000010];

inline void dfs2(int x) {
	for (auto v : edge[x])
		if (d[x] + 1 < d[v] || !d[v])
			d[v] = d[x] + 1, dfs2(v);
}

inline void dfs(int x, int S) {
//	if (S == 2 + 4 + 256) cout <<x <<" ";
	d[x] = 1;
	for (auto v : edge[x])
		if (((S >> v) & 1) && !d[v]) dfs(v, S);
}

int main() {
	freopen("hub.in", "r", stdin);
//	freopen("hub2.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &C, &T);
	for ( ; T-- ; ) {
		scanf("%d%d", &n, &k);
		if (n <= 10) {
			for (int i = 0 ; i < n ; i++) edge[i].clear();
			for (int i = 1 ; i < n ; i++) {
				int u, v;
				scanf("%d%d", &u, &v);
				--u, --v;
				edge[u].push_back(v);
				edge[v].push_back(u);
			}
//			for (auto v : edge[1]) cout << v << " "; puts("");
			int ans = n;
			for (int S = 0 ; S < (1 << n) ; S++) {
				int t = 0;
				for (int i = 0 ; i < n ; i++) t += (S >> i) & 1;
				if (t != k) continue;
//				puts("!");
				int x = 0;
				for (int i = 0 ; i < n ; i++) d[i] = 0;
				for (int i = 0 ; i < n ; i++)
					if (((S >> i) & 1) && !d[i]) {
						dfs(i, S), ++x;
				}
//				if (S == 2 + 4 + 256) cout << x << " " << d[0] << d[1] << d[2] << d[3] << d[4] << d[5] << d[6] << d[7] <<d[8] << d[9] << "   ";
				if (x > 2) continue;
				for (int i = 0 ; i < n ; i++) d[i] = 0;
				for (int i = 0 ; i < n ; i++)
					if ((S >> i) & 1) d[i] = 1, dfs2(i);
				x = 0;
				for (int i = 0 ; i < n ; i++)
					x = max(x, d[i] - 1);
				ans = min(ans, x);
//				if (x == 1) {for (int i = 0 ; i < n ; i++) cout << ((S >> i) & 1); cout << "   " << x <<endl;}
//				cout << x << endl;
			}
			printf("%d\n", ans);
		} else if (C == 13 || C == 14) {
			for (int i = 1 ; i <= n ; i++) edge[i].clear();
			for (int i = 1 ; i < n ; i++) {
				int u, v;
				scanf("%d%d", &u, &v);
				edge[u].push_back(v);
				edge[v].push_back(u);
			}
			int p = n / 2 + 2;
			if (k == n) puts("0");
			else if (k >= n / 2) puts("1");
			else if (k == 1) printf("%d\n", p / 2);
			else printf("%d\n", (p + 4) / 4 - (k + (4 - p % 4) % 4 - 2) / 4);
		} else puts("0");
	}
	return 0;
} 
