#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 4e3 + 5;

int c, T;

int n, d;

int x[N];

int dis[N];

int nxt[N * N], to[N * N], h[N];

int cnt[N];

int tot;

void add (int u, int v) {
	tot++;
	nxt[tot] = h[u];
	h[u] = tot;
	to[tot] = v;
}

bool vis[N];

int ans;

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {//½¨Í¼¼Ó±ß 
			for (int j = 1; j < i; j++) {
				if (abs (x[i] - x[j]) <= d) {
					add (i, j);
					add (j, i);
				}
			}
		}
		for (int s = 1; s <= n; s++) {
			for (int i = 1; i <= n; i++) {
				dis[i] = 1e18;
				vis[i] = 0;
				cnt[i] = 0;
			}
			dis[s] = 0;
			for (int i = 1; i <= n; i++) {
				int k = 0, mx = 1e18;
				for (int j = 1; j <= n; j++) {
					if (!vis[j] && dis[j] < mx) {
						mx = dis[j];
						k = j;
					}
				}
				vis[k] = 1;
				for (int j = h[k]; j; j = nxt[j]) {
					int y = to[j];
					if (dis[y] > dis[k] + 1) {
						dis[y] = dis[k] + 1;
						cnt[y] = 1;
					}
					else if (dis[y] == dis[k] + 1) {
						cnt[y]++;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				if (cnt[i] == 2) {
					ans++;
				}
			}
		}
		cout << ans / 2 << "\n";
		ans = tot = 0;
		for (int i = 1; i <= n; i++) {
			h[i] = 0;
		}
	}
	
	return 0;
}
