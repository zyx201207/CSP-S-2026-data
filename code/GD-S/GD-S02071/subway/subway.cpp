#include <bits/stdc++.h>
#define ft first
#define sd second
#define md make_pair
#define pb push_back
#define gc getchar
#define pc putchar
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll res = 0, f = 1; char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = gc();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = gc();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const int N = 5e2 + 5, M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll w[M];
int k[N];
vector<pii> ve[N];
vector<pii> subway[M];
ll f[N][N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++)
	{
		k[i] = read();
		for (int j = 1; j <= k[i]; j++)
		{
			int a = read(), t = read();
			ve[i].pb(md(a, t));
			subway[a].pb(md(i, t));
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= m; i++)
	{
		int len = subway[i].size();
		for (int uu = 0; uu < len; uu++)
		{
			for (int vv = uu + 1; vv < len; vv++)
			{
//				if (uu == vv) continue;
				pii pu = subway[i][uu], pv = subway[i][vv];
				ll u = pu.ft, tu = pu.sd, v = pv.ft, tv = pv.sd;
				f[u][v] = f[v][u] = min(f[u][v], tu + tv);
			}
		}
	}
	for (int i = 1; i <= n; i++) f[i][i] = 0;
//	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cout << f[i][j] << " \n"[j == n];
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--)
	{
		int x = read(), y = read();
		ll ans = INF;
		for (pii pu : subway[x])
			for (pii pv : subway[y])
			{
				ll u = pu.ft, tu = pu.sd, v = pv.ft, tv = pv.sd;
				ans = min(ans, tu + f[u][v] + tv);
			}
		writech(w[x] + w[y] + ans, '\n');
	}
	return 0;
}
/*
start coding at 14:56
finish coding at 15:16
*/ 
