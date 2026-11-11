#include<bits/stdc++.h>
using namespace std;
namespace IO {
	constexpr int bufsize = 230005;
	char buf[bufsize], *f1, *f2;
	char gtchar() {return f1 == f2 && (f2 = buf + fread(f1 = buf, 1, bufsize, stdin)) == buf? EOF: *f1++;}
	template<typename t> void read(t &ret)
	{
		int f = ret = 0;
		char ch = gtchar();
		while(!isdigit(ch)) f = ch == '-', ch = gtchar();
		while(isdigit(ch)) ret = ret * 10 + (ch ^ 48), ch = gtchar();
		if(f) ret = -ret;
	}
	template<typename t, typename ...T> void read(t &a, T &...b) {read(a), read(b...);}
} using IO::read;
typedef long long ll;
constexpr ll inf = 1e16;
constexpr int maxn = 5e5 + 5;
int testid, n, m, mxd, q, w[maxn], deg[maxn];
bool vis[505];
ll f[505][505];
pair<int, int> line[maxn][20];
void link(int a, int b, ll c)
{
	f[a][b] = min(f[a][b], c);
	f[b][a] = min(f[b][a], c);
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(testid, n, m, mxd, q);
	for(int i = 1; i <= n; i++) fill(f[i] + 1, f[i] + 1 + n, inf), f[i][i] = 0;
	for(int i = 1; i <= m; i++) read(w[i]);
	for(int i = 1, cc; i <= n; i++)
	{
		read(cc);
		for(int j = 1, x, tx; j <= cc; j++)
		{
			read(x, tx), line[x][deg[x]] = {i, tx};
			for(int k = 0; k < deg[x]; k++)
				link(line[x][k].first, i, line[x][k].second + tx);
			++deg[x];
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
			f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
	for(int i = 1, a, b; i <= q; i++)
	{
		read(a, b);
		ll ans = inf;
		for(int ii = 0; ii < deg[a]; ii++) for(int jj = 0; jj < deg[b]; jj++)
			ans = min(ans, f[line[a][ii].first][line[b][jj].first] + line[a][ii].second + line[b][jj].second);
		ans += w[a] + w[b];
		printf("%lld\n", ans);
	}
	return 0;
}