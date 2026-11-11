#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 5000;
int a[MAXN | 1], l[MAXN | 1], r[MAXN | 1];
int vis[MAXN | 1];
int dist[MAXN | 1];
bool sol[MAXN | 1];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int C, T;
	scanf("%d%d", &C, &T);
	while (T--) {
		int n, d;
		scanf("%d%d", &n, &d);
		l[0] = 1;
		bool solved = false;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			l[i] = l[i - 1];
			while (l[i] < i && a[i] - a[l[i]] > d) ++l[i];
		}
		for (int i = 2; i <= n; ++i) {
			if (a[i] - a[i - 1] > d) {
				solved = true;
				printf("0\n");
				break;
			}
		}
		if (solved) continue;
		r[n] = n;
		for (int i = n - 1; i >= 1; --i) {
			r[i] = r[i + 1];
			while (r[i] > i && a[r[i]] - a[i] > d) --r[i];
		}
		ull cnt = 0;
		for (int U = 1; U <= n; ++U) {
			queue<pair<int, int>> q;
			memset(sol, 0, sizeof(sol));
			memset(dist, 0x3F, sizeof(dist));
			q.emplace(U, 0);
			vis[U] = 1; dist[U] = 0;
			while (!q.empty()) {
				int u = q.front().first; int d = q.front().second;
				q.pop();
				sol[u] = true;
				
				for (int v = l[u]; v <= r[u]; ++v) {
					if (!sol[v] && (dist[v] == 0x3F3F3F3F3F3F3F3F || d + 1 <= dist[v])) {
						if (dist[v] == 0x3F3F3F3F3F3F3F3F) {
							dist[v] = d + 1;
							vis[v] = vis[u];
						} else vis[v] += vis[u];
						q.emplace(v, d + 1);
					}
				}
			}
			
			for (int i = 1; i <= n; ++i) {
				if (i == U) continue;
				if (vis[i] == 2) {
					++cnt;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
	return 0;
}

