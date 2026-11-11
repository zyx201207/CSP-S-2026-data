#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace _ {
	
	const int N = 2e5+10;
	const int M = 4e5+10;
	
	int n, m;
	
	int c, T;
	
	int cnt, head[N];
	int nxt[M], to[M];
	
	int fa[N][20];
	int dep[N];
	
	void connect(int u, int v) {
		cnt++, nxt[cnt] = head[u];
		head[u] = cnt, to[cnt] = v;
	}
	
	void solve() {
		
		cin >> n >> m;
		for (int i = 1;i< n;i++) {
			int u, v; cin >> u >> v;
			connect(u, v);
			connect(v, u);
		}
		
	}
	
	signed main() {
		
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);		
		
		cin >> c >> T;
		while (T--) solve();
		
		return 0;
	}
	
}

signed main() {
	return _::main();
}
