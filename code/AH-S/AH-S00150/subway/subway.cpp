#include <bits/stdc++.h>
using namespace std;
class IO {
	char put [35];
	int c, top;
public :
	IO & operator >> (int & a)
	{
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar_unlocked ());
		for (a = 0; 47 < c && c < 58; c = getchar_unlocked ()) a = (a << 3) + (a << 1) + c - 48;
		return * this;
	}
	IO & operator >> (string & s)
	{
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar_unlocked ());
		for (s = ""; c != ' ' && c != '\n' && c != '\r' && 30 < c; c = getchar_unlocked ()) s += c;
		return * this;
	}
	IO & operator << (const long long & a)
	{
		unsigned long long p = a;
		if (a < 0) putchar ('-'), p = - p;
		if (a) {
			for (top = 0; p; p /= 10) put [++ top] = p % 10 + 48;
			for (; top; -- top) putchar (put [top]);
		} else putchar ('0');
		return * this;
	}
	IO & operator << (const char & c) {putchar (c); return * this;}
	IO & operator << (const char * s) {while (* s) putchar (* s ++); return * this;}
} IO;
pair <int, int> G [500009][22];
long long g [507][507], ans;
int c, m, n, d, q;
int Gtot [500009];
int t___ [500009];
int main ()
{
	freopen ("subway.out", "w", stdout);
	freopen ("subway.in", "r", stdin);
	IO >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i) IO >> t___ [i];//m
	for (int i = 1, k; i <= n; ++ i)//∑n_{i=1}^n k_i
	{
		IO >> k;
		for (int a, w; k; -- k)
			IO >> a >> w, G [a][++ Gtot [a]] = {w, i};
	}
	//~ if (11 < c && c < 20) {
		//~ return 0;01 bfs
	//~ }
	//E = 1e6, V 约等于 5e5
	//q = 1e5
	//d = 20
	//q E log V
	//2e8
	//n^3=1.25e8
	// m <-> m
	//q*400=4e7
	for (int i = 1; i <= n; ++ i)//n^2+n
	{
		for (int j = 1; j <= n; ++ j) g [i][j] = 0x3f3f3f3f3f3f3f3f;
		g [i][i] = 0;
	}
	for (int k = 1; k <= m; ++ k)//O(md^2)
		for (int i = Gtot [k]; i; -- i)
			for (int j = i - 1; j; -- j)
			{
				int & u = G [k][i].second, & v = G [k][j].second;
				long long w = G [k][i].first + G [k][j].first;
				g [u][v] = min (g [u][v], w), g [v][u] = min (g [u][v], w);
			}
	for (int k = 1; k <= n; ++ k)//O(n^3)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				g [i][j] = min (g [i][j], g [i][k] + g [k][j]);
	for (int l, r; q; -- q)//O(qd^2)
	{
		IO >> l >> r;
		if (l != r) {
			ans = 0x3f3f3f3f3f3f3f3f;
			for (int i = Gtot [l]; i; -- i)
				for (int j = Gtot [r]; j; -- j)
					ans = min (ans, G [l][i].first + g [G [l][i].second][G [r][i].second] + G [r][i].first);
		 IO << ans + t___ [l] + t___ [r] << '\n';// + dis [l][r]...;
		} else IO << "0\n";
	}//(m+q)d^2+∑n_{i=1}^n k_i+(n^4+1)/(n+1)
	return 0;
}
