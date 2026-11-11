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
	
	const int SN = 310;
	const int N = 2e6 + 10;
	int c, T, n; LL d, a[N];
	
	int dis[SN], way[SN], G[SN][SN];
	void bfs(int s) {
		memset(dis, 0x3f, sizeof(dis));
		memset(way, 0, sizeof(way));
		dis[s] = 0, way[s] = 1;
		queue<int> Q; Q.push(s);
		while(!Q.empty()) {
			int x = Q.front(); Q.pop();
			FO(y, 1, n) {
				if(!G[x][y]) continue;
				if(dis[x] + 1 < dis[y]) dis[y] = dis[x] + 1, way[y] = way[x], Q.push(y);
				else if(dis[x] + 1 == dis[y]) way[y] += way[x];
			}
		}
	}
	void work() {
		c=read(), T=read();
		while(T--) {
			n=read(), d=read(); LL ans = 0;
			
			FO(i, 1, n) a[i]=read();
			
			if(n == 1) {
				puts("0"); continue;
			}
			if(1 <= c && c <= 10) {
				memset(G, 0, sizeof(G));
				FO(i, 1, n) FO(j, 1, n) if(abs(a[i] - a[j]) <= d) G[i][j] = 1;
				FO(i, 1, n) {
					bfs(i);
					FO(j, 1, n) if(way[j] == 2) ++ans;
				}
				ans >>= 1;
			}
			else{
				LL dt = a[2] - a[1]; int v = min(1LL*n, d / dt);
				if(v > 1 && 2*v-1 <= n) ans = n - (2*v-1);
			}
			printf("%lld\n", ans);
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	work();
	return 0;
}
