#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500010];
struct fff
{
	int k, a[500010], t[500010];
} zhi[510];
struct rrr
{
	int x, y;
} r[100010];
bool cmp (fff f1, fff f2)
{
	return f1.a[1] < f2.a[1];
}
int ttt (int x, int y)
{
	long long xx, z = 10000000000, yy, z2 = 10000000000, z3 = 10000000000;
	for (int i = 1; i <= n; i++)
	{
		if (zhi[i].a[1] == x && z > zhi[i].t[1])
		{
			xx = i;
			z = zhi[i].t[1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (zhi[i].a[zhi[i].k] == y && z2 > zhi[i].t[zhi[i].k])
		{
			yy = i;
			z2 = zhi[i].t[zhi[i].k];
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (zhi[xx].a[i] == zhi[yy].a[i] && z3 > zhi[xx].t[i] + zhi[yy].t[i])
				z3 = zhi[xx].t[i] + zhi[yy].t[i];
	long long zzz = z+z2+z3, z4 = 10000000000;
	for (int i = 1; i <= n; i++)
		if (zhi[i].a[1] == x && zhi[i].a[zhi[i].k] == y && z > zhi[i].t[1] + zhi[i].t[zhi[i].k])
			z4 = zhi[i].t[1] + zhi[i].t[zhi[i].k];
	return max (zzz, z4);
}
int main ()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> zhi[i].k;
		for (int j = 1; j <= zhi[i].k; j++)
			cin >> zhi[i].a[j] >> zhi[i].t[j];
	}
	for (int i = 1; i <= q; i++)
		cin >> r[i].x >> r[i].y;
	sort (zhi+1, zhi+1+n, cmp);
	for (int i = 1; i <= q; i++)
	{
		long long cnt = 0;
		cnt += w[r[i].x];
		cnt += ttt(r[i].x, r[i].y);
		cnt += w[r[i].y];
		cout << cnt << '\n';
	}
	return 0;
}
