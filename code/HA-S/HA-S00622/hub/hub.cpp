#include <bits/stdc++.h>

#define fileio(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout);

using namespace std;

void solve1314() {
	int n, k;
	cin >> n >> k;

	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
	}

	int ans = n;

	int m = (n - 1) / 2; // 6

	if(m % 2 == 0) {
		int t = m / 2; // 3

		if(t % 2 == 1) {
			int b = (t - 1) / 2; // 1
			if(k % 2 == 0) {
				int g = k / 2;
				int f = (g - 1) / 2;

				ans = min(ans, max(b - f + 1, 0));
			} else {
				int g = (k + 1) / 2;
				int f = (g - 1) / 2;

				ans = min(ans, max(b - f + 1, 0));
			}
		} else {
			int b = t / 2; // 1

			if(k % 2 == 0) {
				int g = k / 2;
				int f = (g - 1) / 2;

				ans = min(ans, max(b - f + 2, 0));
			} else {
				int g = (k + 1) / 2;
				int f = (g - 1) / 2;

				ans = min(ans, max(b - f + 2, 0));
			}
		}
	} else {
		int t = m / 2; // 3

		if(t % 2 == 1) {
			int b = (t - 1) / 2; // 1

			int g = k / 2;
			int f = (g - 1) / 2;

			ans = min(ans, max(b - f + 1, 0));
		} else {
			int b = t / 2;

			int g = k / 2;
			int f = (g - 1) / 2;

			ans = min(ans, max(b - f + 2, 0));
		}
	}

	cout << ans << '\n';
}

int u[1050], v[1050];
vector<int> g[1050];
bool f[1050];
int fa[1050];
int n, k;

int lookup(int i) {
	return fa[i] == i ? i : fa[i] = lookup(fa[i]);
}

bool validate() {
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
	}

	for(int i = 1; i < n; i++) {
		if(f[u[i]] && f[v[i]]) {
			int fu = lookup(u[i]);
			int fv = lookup(v[i]);

			fa[fu] = fv;
		}
	}

	int res = 0;

	for(int i = 1; i <= n; i++) {
		if(f[i] && fa[i] == i) {
			res++;
		}
	}

	return res <= 2;
}

int dep[1050];
int mdis[1050];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;

	for(auto v : g[u]) {
		if(v == fa) {
			continue;
		}

		dfs(v, u);
	}
}

void solve() {
	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		g[i].clear();
	}

	for(int i = 1; i < n; i++) {
		cin >> u[i] >> v[i];

		g[u[i]].emplace_back(v[i]);
		g[v[i]].emplace_back(u[i]);
	}

	int ans = 1111111;
	int st = 1 << n;

	/*f[1] = f[2] = f[3] = f[6] = f[8] = true;
	for(int i = 1; i <= n; i++) {
		mdis[i] = 1050;
	}

	int rad = 0;

	for(int i = 1; i <= n; i++) {
		if(f[i]) {
			dfs(i, 0);

			for(int j = 1; j <= n; j++) {
				mdis[j] = min(mdis[j], dep[j] - 1);
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		rad = max(rad, mdis[i]);
	}

	ans = min(ans, rad);*/

	for(int S = 0; S < st; S++) {
		int len = 0;

		for(int j = 1; j <= n; j++) {
			f[j] = false;
		}

		for(int j = 1; j <= n; j++) {
			if(S & (1 << (j - 1))) {
				len++;
				f[j] = true;
			}
		}

		if(len > k) {
//			cout << "passed1" << endl;
			continue;
		}

		if(!validate()) {
//			cout << "passed2" << endl;
			continue;
		}

		for(int i = 1; i <= n; i++) {
			mdis[i] = 1050;
		}

		int rad = 0;

		for(int i = 1; i <= n; i++) {
			if(f[i]) {
				dfs(i, 0);

				for(int j = 1; j <= n; j++) {
					mdis[j] = min(mdis[j], dep[j] - 1);
				}
			}
		}

		for(int i = 1; i <= n; i++) {
			rad = max(rad, mdis[i]);
		}

		ans = min(ans, rad);
	}

	cout << ans << '\n';
}

int main() {
	fileio("hub")
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int c, t;
	cin >> c >> t;

	if(c >= 13 && c <= 14) {
		while(t--) {
			solve1314();
		}
	}

	if(c <= 3) {
		while(t--) {
			solve();
		}
	}

	return 0;
}
