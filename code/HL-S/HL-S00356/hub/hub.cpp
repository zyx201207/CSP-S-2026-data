#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10, inf = 0x3f3f3f3f3f3f3f3f;

int n, k, d[N];
vector<int> e[N]; 

bool chk(int s)
{
	for (int i = 1; i <= n; i++) d[i] = inf;
	int l = s, r = (n + 1) / 2 - s;
	queue<int> q;
	int o = (k + 1) / 2;
	for (int i = 1; i <= o; i++) {
		q.push(l), d[l] = 0, l++;
		if (l > n) break;
	}
	o = k - o;
	for (int i = 1; i <= o; i++) {
		q.push(r), d[r] = 0, r--;
		if (r < 1) break;
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v : e[u]) {
			if (d[v] == inf) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
	return ans <= s;
}

int S = 0, w[100], p[100];

void dfs(int u, int fa, int d, int o)
{
	S |= (1 << (u - 1));
	for (auto v : e[u]) {
		if (v == fa) continue;
		if (d + 1 <= o) dfs(v, u, d + 1, o);
	}
}

int fifa(int x) { return p[x] == x ? x : p[x] = fifa(p[x]); }

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	if (n <= 10) {
		for (int o = 0; o <= n; o++) {
			for (int i = 1; i <= n; i++) {
				S = 0;
				dfs(i, 0, 0, o);
				w[i] = S;
			} // 我有 n 個集合 每個集合我都至少選擇一個點 然後
			bool WXY = 0;
			for (int X = 0; X < (1 << n); X++) {
				// 我要選擇這些點
				// 1. 至多兩個連通塊
				// 2. 合法
				for (int i = 1; i <= n; i++) p[i] = i;
				for (int i = 1; i <= n; i++) {
					for (auto v : e[i]) {
						if ((X & (1 << (i - 1))) && (X & (1 << (v - 1)))) {
							int px = fifa(i), py = fifa(v);
							if (px == py) continue;
							p[px] = py;
						}
					}
				}
				bool ok = 1;
				int cc = 0, ccc = 0;
				for (int i = 1; i <= n; i++) if (p[i] == i && (X & (1 << (i - 1)))) ccc++;
				for (int i = 1; i <= n; i++) {
					if (!(w[i] & X)) ok = 0;
					if (X & (1 << (i - 1))) cc++;
				}
				if (!ok || cc > k || ccc > 2) continue;
				WXY = 1;
			}
			if (WXY) {
				cout << o << "\n";
				break;
			}
		}
	} else {
		int l = 0, r = n, res = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (chk(mid)) r = (res = mid) - 1;
			else l = mid + 1;
		}
		cout << res << "\n";
	} 
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	cin.tie(0)->ios::sync_with_stdio(false);
	int c, t; cin >> c >> t;
	while (t--) solve();	
	return 0;
}