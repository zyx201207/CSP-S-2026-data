#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 500 + 10,M = 5e5 + 10,INF = 0x3f3f3f3f3f3f3f3f;
int read() {
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + (c ^ 48),c = getchar();
	return x;
}
void write(int x) {
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
int c,n,m,d,Q;
int dis[N][N];
int w[M];
vector<pii> cov[M];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	c = read(),n = read(),m = read(),d = read(),Q = read();
	for(int i = 1; i <= m; i ++) w[i] = read();
	for(int i = 1; i <= n; i ++) {
		int k = read();
		dis[i][i] = 0;
		for(int j = 1; j <= k; j ++) {
			int x = read(),t = read();
			cov[x].emplace_back(i,t);
		}
	}
	for(int st = 1; st <= m; st ++) {
		int k = cov[st].size();
		if(k == 1) continue;
		for(int i = 0; i < k; i ++) {
			for(int j = i + 1; j < k; j ++) {
				int u = cov[st][i].fi,v = cov[st][j].fi,ww = cov[st][i].se + cov[st][j].se;
				dis[u][v] = min(dis[u][v],ww);
				dis[v][u] = min(dis[v][u],ww);
			}
		}
	}
	for(int k = 1; k <= n; k ++) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(dis[i][k] == INF || dis[k][j] == INF) continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(Q --){
		int x = read(),y = read();
		int ans = INF;
		int k1 = cov[x].size(),k2 = cov[y].size();
		for(int i = 0; i < k1; i ++) {
			for(int j = 0; j < k2; j ++) {
				int u = cov[x][i].fi,v = cov[y][j].fi,ww = cov[x][i].se + cov[y][j].se;
				ans = min(ans,dis[u][v] + ww);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
可以对线路建点
然后通过地铁站连边
这样有一个1e9的做法
然后现在的问题是询问太多
考虑对询问去重
没啥用好像
有没有其他离线的方法
wow，我会了，就是路线建点
*/
