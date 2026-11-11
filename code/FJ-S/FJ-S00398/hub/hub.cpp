// 2026 CSP-S D ( hub )
#include <bits/stdc++.h>
using namespace std;
namespace kqpkao_namespace{

const int N = 1e6 + 5, inf = 1e9;
int n, k, pos[N], fa[N], ans;
int qh, qt, q[N], d[N];
vector<int> g[N];
bool vis[N];
int Find(int fx){
	if (fa[fx] != fx){
		fa[fx] = Find(fa[fx]);
	}
	return fa[fx];
}
bool getNext(){
	int z = -1;
	for (int i = 0; i < k; ++i){
		if (pos[k - i] != n - i){
			z = i;
			break;
		}
	}
	if (z == -1){
		return false;
	}
	++pos[k - z];
	for (int i = k - z; i < k; ++i){
		pos[i + 1] = pos[i] + 1;
	}
	return true;
}
inline void solve(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i){
		g[i].clear();
	}
	for (int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i){
		g[i].shrink_to_fit();
	}
	for (int i = 1; i <= k; ++i){
		pos[i] = i;
	}
	ans = inf;
	while (true){
		for (int i = 1; i <= n; ++i){
			vis[i] = false;
			d[i] = inf;
			fa[i] = i;
		}
		for (int i = 1; i <= k; ++i){
			vis[pos[i]] = true;
		}
		for (int u = 1; u <= n; ++u){
			for (int v : g[u]){
				if (vis[u] && vis[v]){
					int x = Find(u);
					int y = Find(v);
					if (x != y){
						fa[x] = y;
					}
				}
			}
		}
		int tot = 0;
		for (int i = 1; i <= k; ++i){
			if (vis[Find(pos[i])]){
				vis[Find(pos[i])] = false;
				++tot;
			}
		}
		if (tot > 2){
			if (!getNext()){
				break;
			}
			continue;
		}
		qh = 1;
		qt = k;
		for (int i = 1; i <= k; ++i){
			q[i] = pos[i];
			d[pos[i]] = 0;
			vis[pos[i]] = true;
		}
		int now = 0;
		while (qh <= qt){
			int u = q[qh];
			++qh;
			now = max(now, d[u]);
			for (int v : g[u]){
				if (!vis[v]){
					vis[v] = true;
					d[v] = d[u] + 1;
					++qt;
					q[qt] = v;
				}
			}
		}
		ans = min(ans, now);
		if (!getNext()){
			break;
		}
	}
	printf("%d\n", ans);
	return;
}
inline int k_main(){
	int testid, _;
	scanf("%d%d", &testid, &_);
	while (_--){
		solve();
	}
	return 0;
}

}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int k_ret = kqpkao_namespace::k_main();
	return k_ret;
}
