#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
const int N = 2e6 + 10, INF = 1e9;

LL x[N];
int pre[N], nxt[N], cntp[N], cntn[N];
LL l[N], r[N];

LL read()
{
	LL x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void write(LL x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x <= 9) {putchar(x + '0'); return;}
	write(x / 10); putchar(x % 10 + '0');
}

bool check(int a, int b, int c, int d) {return a < b && b < c && c < d;}

void solve()
{
	int n = (int)read(); LL d = read();
	for (int i = 1; i <= n; i ++ ) x[i] = read();
	for (int i = 1; i <= n; i ++ ) pre[i] = nxt[i] = cntp[i] = cntn[i] = 0, l[i] = r[i] = 0;
	pre[n + 1] = n + 1;
	for (int i = n; i; i -- )
	{
		pre[i] = min(pre[i + 1], i);
		while (pre[i] - 1 >= 1 && x[i] - x[pre[i] - 1] <= d) pre[i] -- ;
		if (pre[i] != i) cntp[pre[i]] ++ ;
//		cout << pre[i] << endl;
	}
	for (int i = 1; i <= n; i ++ )
	{
		nxt[i] = max(i, nxt[i - 1]);
		while (nxt[i] + 1 <= n && x[nxt[i] + 1] - x[i] <= d) nxt[i] ++ ;
		if (nxt[i] != i) cntn[nxt[i]] ++ ;
//		cout << nxt[i] << endl;
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (pre[i] != i && nxt[pre[i]] == i) l[i] = l[pre[i]] + (LL)cntn[i];
	}
	for (int i = n; i; i -- )
	{
		if (nxt[i] != i && pre[nxt[i]] == i) r[i] = r[nxt[i]] + (LL)cntp[i];
	}
	LL res = 0;
	for (int a = 1; a <= n; a ++ )
	{
		int c = nxt[a], d = nxt[c], b = pre[d];
		if (!check(a, b, c, d) || b != c - 1 || pre[b] != a) continue;
		res += l[a] * r[d];
	}
	for (int a = 1; a <= n; a ++ )
	{
		int c = nxt[a], d = nxt[c], b = pre[d];
		if (!check(a, b, c, d) || b != c - 1) continue;
		res += r[d];
	}
	for (int d = 1; d <= n; d ++ )
	{
		int b = pre[d], a = pre[b], c = nxt[a];
		if (!check(a, b, c, d) || b != c - 1) continue;
		res += l[a];
	}
	for (int a = 1; a <= n; a ++ )
	{
		int c = nxt[a], b = c - 1;
//		cout << a << ' ' << c << ' ' << b << ' ' << ag[b].size() << endl;
		if (!check(a, b, c, INF) || nxt[c] == c) continue;
		int w = 0; if (pre[c] == b) w = 1;
		res += (LL)(cntp[b] - w);
//		if (ag[b][l] <= nxt[c]) res += (LL)(l + 1 - w);
	}
	write(res); putchar('\n');
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	LL C = read(), T = read();
	while (T -- ) solve();
	return 0;
}
