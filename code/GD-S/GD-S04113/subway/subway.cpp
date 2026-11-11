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
	
	const int N = 510;
	const int M = 5e5 + 10;
	const int D = 30;
	const LL INF = 0x3f3f3f3f3f3f3f3fLL;
	struct GPH {
		int head[N], to[M], w[M], nex[M], tot;
		void lnk(int x, int y, int z) {
			nex[++tot] = head[x], to[tot] = y, w[tot] = z, head[x] = tot;
		}
	}gp;
	int n, m, d, q; LL w[M];
	int cnt[M], a[M][D]; LL t[M][D];
	
	LL dis[N][N];
	void init() {
		memset(dis, 0x3f, sizeof(dis));
		FO(i, 1, n) dis[i][i] = 0;
		FO(i, 1, n) {
			for(int j = gp.head[i]; j; j = gp.nex[j]) {
				int y = gp.to[j]; LL z = gp.w[j];
				FO(k, 1, cnt[y])
					dis[a[y][k]][i] = dis[i][a[y][k]] = min(dis[i][a[y][k]], z + t[y][k]);
			}
		}
	}
	void Floyd() {
		FO(k, 1, n) FO(i, 1, n) FO(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	void work() {
		read(); n=read(), m=read(), d=read(), q=read();
		FO(i, 1, m) w[i]=read();
		FO(i, 1, n) {
			int K=read();
			FO(j, 1, K) {
				int x=read(), y=read(), id = ++cnt[x];
				a[x][id] = i, t[x][id] = y;
				gp.lnk(i, x, y);
			}
		}
		
		init();
		
		Floyd();
		while(q--) {
			int x=read(), y=read(); LL ans = INF;
			FO(i, 1, cnt[x])
				FO(j, 1, cnt[y])
					ans = min(ans, t[x][i] + t[y][j] + dis[a[x][i]][a[y][j]]);

			ans += w[x] + w[y];
			printf("%lld\n", ans);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	work();
	return 0;
}
