#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int N = 2e6 + 5; 
int c, T, n; ll L;
ll a[N];

namespace solveA {
	void main() {
		ll d = a[2] - a[1];
		ll k = L / d;
		if(k == 0 || k == 1) {
			cout << 0 << endl;
			return; 
		}
		cout << max(0ll, n - 2 * k + 1) << endl;
	}
}

namespace baoli {
	int nxt[N], vis[N], dis[N], way[N];
	queue<int> q;
	void topsort(int s) {
		q.push(s); vis[s] = 1; dis[s] = 0; way[s] = 1;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int v = u + 1; v <= nxt[u]; v++) {
				if(dis[u] + 1 < dis[v]) {
					dis[v] = dis[u] + 1;
					way[v] = way[u];
				} else if(dis[u] + 1 == dis[v])
					way[v] += way[u];
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	void main() {
		for(int i = 1; i <= n; i++) {
			nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + L) - a - 1;
//			cout << nxt[i] << " ";
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			memset(dis, 0x3f, sizeof(dis));
			memset(way, 0, sizeof(way));
			topsort(i);
			for(int j = 1; j <= n; j++)
				if(way[j] == 2) ans++;
		}
		cout << ans << endl;
	}
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while(T--) {
		cin >> n >> L;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(n <= 3) {
			cout << 0 << endl;
			continue;
		}
		if(c == 11 || c == 12) solveA::main();
		else baoli::main(); 
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

