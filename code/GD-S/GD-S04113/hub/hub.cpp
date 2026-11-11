#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define FO(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define RP(i, a, b) for(int i = (a); i >= (int)(b); --i)
LL read() {
	LL s = 0, f = 1; char ch; while(isspace(ch=getchar()));
	while(ch == '-' || isdigit(ch)) ch == '-' ? (f=-1) : (s=s*10+ch-'0'), ch=getchar();
	return s*f;
}

namespace {
	
	const int N = 2e6 + 10;
	const int INF = 0x3f3f3f3f;
	int c, T, n, m;
	struct GPH {
		int head[N], to[N<<1], nex[N<<1], tot;
		void lnk(int x, int y) {
			nex[++tot] = head[x], to[tot] = y, head[x] = tot;
			nex[++tot] = head[y], to[tot] = x, head[y] = tot;
		}
	}gp;
	int cor[N], vis[N], cnt;
	
	void dfs1(int x) {
		vis[x] = 1;
		for(int i = gp.head[x]; i; i = gp.nex[i]) {
			int y = gp.to[i]; if(!cor[y] || vis[y]) continue;
			dfs1(y);
		}
	}
	
	int dis[N];
	void dfs2(int x, int fa, int d) {
		dis[x] = min(dis[x], d);
		for(int i = gp.head[x]; i; i = gp.nex[i]) {
			int y = gp.to[i]; if(y == fa) continue;
			dfs2(y, x, d+1);
		}
	}
	void work() {
		c=read(), T=read();
		while(T--) {
			n=read(), m=read();
			gp.tot = 0; FO(i, 1, n) gp.head[i] = 0;
			FO(i, 1, n-1) gp.lnk(read(), read());
			int ans = INF;
			FO(i, 0, (1<<n)-1) {
				if(__builtin_popcount(i) != m) continue;
				memset(cor, 0, sizeof(int)*(n+1));
				memset(vis, 0, sizeof(int)*(n+1));
				memset(dis, 0x3f, sizeof(int)*(n+1));
				FO(j, 1, n) if((i >> (j-1)) & 1) cor[j] = 1;
				cnt = 0;
				FO(j, 1, n) if(cor[j] && !vis[j]) ++cnt, dfs1(j);
				if(cnt > 2) continue;
				
				FO(j, 1, n) if(cor[j]) dfs2(j, 0, 0);
				int res = 0;
				FO(j, 1, n) res = max(res, dis[j]);
				ans = min(ans, res);
			}
			printf("%d\n", ans);
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	work();
	return 0;
}
