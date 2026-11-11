#include <bits/stdc++.h>
using namespace std;
namespace FastIO{
	const int NN = 1<<17;
	char buf[NN], *p1, *p2;
	#define gt() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, NN, stdin), p1 == p2)? EOF:*p1++)
	int read()
	{
		int x = 0, f = 1;
		char c = gt();
		while(c < '0' || c > '9')
		{
			if(c == '-')
				f = -1;
			c = gt();
		}
		while('0' <= c && c <= '9')
			x = x*10+(c^48), c = gt();
		return x*f;
	}
	void wt(long long x)
	{
		if(x > 9)
			wt(x/10);
		putchar(x%10^48);
	}
	void write(long long x)
	{
		if(x < 0)
		{
			putchar('-');
			x = -x;
		}
		wt(x);
	}
}
using FastIO::read;
using FastIO::write;
const int N = 510, M = 5e5+10;
typedef pair<int, int> PII;
int n, m, d, q, www[M], hd[M], edge_cnt;
long long dis[N][N];
struct edge{
	int v, w, to;
}e[M];
void add(int u, int v, int w)
{
	e[++edge_cnt] = {v, w, hd[u]};
	hd[u] = edge_cnt;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read();
	n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++)
		www[i] = read();
	for(int i = 1; i <= n; i++)
	{
		int k = read(), a, t;
		while(k--)
		{
			a = read(), t = read();
			add(a, i, t);
		}
	}
	memset(dis, 0x3f, sizeof dis);
	vector<PII> a(d+5);
	for(int i = 1; i <= m; i++)
	{
		int cnt = 0;
		for(int j = hd[i]; j; j = e[j].to)
			a[++cnt] = (PII){e[j].v, e[j].w};
		for(int j = 1; j <= cnt; j++)
			for(int k = 1; k <= cnt; k++)
				dis[a[j].first][a[k].first] = min(dis[a[j].first][a[k].first], (long long)a[j].second+a[k].second);
	}
	for(int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	vector<PII> b(d+5);
	while(q--)
	{
		int x = read(), y = read();
		long long ans = 1e18;
		int cntx = 0, cnty = 0;
		for(int i = hd[x]; i; i = e[i].to)
			a[++cntx] = (PII){e[i].v, e[i].w};
		for(int i = hd[y]; i; i = e[i].to)
			b[++cnty] = (PII){e[i].v, e[i].w};
		for(int i = 1; i <= cntx; i++)
			for(int j = 1; j <= cnty; j++)
				ans = min(ans, dis[a[i].first][b[j].first]+a[i].second+b[j].second);
		ans += www[x]+www[y];
		write(ans);
		putchar('\n');
	}
	return 0;
}
