#include <bits/stdc++.h>
using namespace std; typedef long long ll;
const int N = 500005;
int c,n,m,d,q,w[N]; ll dis[505][505];
struct edge {int to,w;}; vector <edge> e[N],f[N];
int read() {
	int w = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) w = w*10+(c-'0'),c = getchar();
	return w;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1;i <= m;i++) w[i] = read();
	for (int i = 1;i <= n;i++) {
		int k = read();
		while (k--) {
			int x = read(),y = read();
			e[i].push_back({x,y}),f[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1;i <= n;i++) dis[i][i] = 0;
	for (int i = 1;i <= n;i++)
		for (edge E:e[i]) for (edge F:f[E.to])
			dis[i][F.to] = min(dis[i][F.to],ll(E.w+F.w));
	for (int k = 1;k <= n;k++) for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	while (q--) {
		int u = read(),v = read(); ll ans = 1e18;
		for (edge E:f[u]) for (edge F:f[v])
			ans = min(ans,E.w+dis[E.to][F.to]+F.w);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
