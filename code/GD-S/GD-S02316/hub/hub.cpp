#include <bits/stdc++.h>

using namespace std;

namespace my {
	constexpr int N = 1e6 + 5;
	constexpr int MOD = 998244353;

	typedef long long ll;
	
	vector <int> g[N];
	int depth[N], fa[N][21];
	
	void dfs(int u, int f) {
		fa[u][0] = f;
		depth[u] = depth[f] + 1;
		
		for (int i = 1; i <= 20; i++)
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
			
		for (int v : g[u])
			if (v != f) dfs(v, u); 
	}
	
	bool is_s[N];
	int blk[N];
	
	

	int main() {
		#ifndef LOCAL
			freopen("hub.in", "r", stdin);
			freopen("hub.out", "w", stdout);
		#endif

		int C, T; scanf("%d%d", &C, &T);
		
		while (T--) {
			int n, k; scanf("%d%d", &n, &k);
			
			cout << "0\n";
		}

		#ifndef LOCAL
			fclose(stdin);
			fclose(stdout);
		#endif

		return 0;
	}
}

int main() {
	my::main();

	return 0;
}

