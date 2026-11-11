#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>

namespace worksimple {
	const int N = 4005;
	std::vector<int> g[N];
	int fa[N];
	int root;
	int disa;
	int n, k;
	void dfs1(int x, int z) {
		fa[x] = z;
		for (int y : g[x]) {
			if (y != z)
				dfs1(y, x);
		}
	}
	int len[N], len2[N], son[N];
	int flen[N];
	void dfsdis(int x, int fa) {
		len[x] = 1;
		len2[x] = -1e9;
		son[x] = 0;
		for (int y : g[x]) {
			if (y == fa || y == disa)
				continue;
			dfsdis(y, x);
			if (len[y] + 1 > len[x]) {
				len2[x] = len[x];
				len[x] = len[y] + 1;
				son[x] = y;
			} else if (len[y] + 1 > len2[x]) {
				len2[x] = len[y] + 1;
			}
		}
	}
	void dfsfdis(int x, int fa) {
		for (int y : g[x]) {
			if (y == fa || y == disa)
				continue;
			flen[y] = flen[x] + 1;
			if (y != son[x]) {
				flen[y] = std::max(flen[y], len[x] + 1);
			} else {
				flen[y] = std::max(flen[y], len2[x] + 1);
			}
			dfsfdis(y, x);
		}
	}
	
	int add1[N], add2[N];
	int f[N][N];
	void upd(int &x, int a) {
		x = std::min(x, a);
	}
	void dfsdp(int x, int fa, int add[]) {
		for (int i = 0; i < len[x]; ++i)
			f[x][i] = 1;
		for (int y : g[x]) {
			if (y != fa && y != disa) {
				dfsdp(y, x, add);
				for (int i = 0; i < len[y]; ++i)
					f[x][i] += f[y][i];
			}
		}
		for (int i = 0; i < len[x]; ++i)
			upd(add[std::max(i, flen[x] - 1)], f[x][i]);
	}
	void calc(int add[]) {
		//以root为根，并且不能走到disa上面，计算用最多k个能得到的最小距离
		dfsdis(root, fa[root]);
		flen[root] = 1;
		dfsfdis(root, fa[root]);
		//现在开始dp
		dfsdp(root, fa[root], add);
	}
	void work() {
		scanf("%d %d", &n, &k);	
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		for (int i = 1; i < n; ++i)	 {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		dfs1(1, 0);

		int ans = 2e9;
		for (int i = 2; i <= n; ++i) {
			memset(add1, 0x3f, sizeof(add1));
			memset(add2, 0x3f, sizeof(add2));
			root = i;
			disa = 0;
			calc(add1);
			root = 1;
			disa = i;
			calc(add2);

			for (int j = 0; j <= n; ++j)
				add1[j] += add2[j];
			for (int j = 0; j <= n; ++j) {
				if (add1[j] <= k) {
					ans = std::min(ans, j);
					break;
				}
			}
			for (int i = 1; i <= n; ++i) {
				add1[i] = add2[i] = 0x3f3f3f3f;
			}
		}
		printf("%d\n", ans);
	}
	void main() {
		int t;
		scanf("%d", &t);
		while (t--)
			work();
	}
}
int main() {
	freopen("hub.in", "r", stdin);	
	freopen("hub.out", "w", stdout);
	int c;
	scanf("%d", &c);
	worksimple::main();
	return 0;
}