#include <bits/stdc++.h>
using namespace std;
struct num
{
	long long s, c, g;
}a[200005];
long long n, m, ans, cnt, x, t[105], q, h;
bool p, f;
bool cmp(num a, num b)
{
	if (a.c == b.c)
	{/*
		if (a.g != b.g)
		{
			return a.g > b.g;
		}*/
		return a.s > b.s;
	}
	return a.c > b.c;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	p = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].s;
		p = (p && a[i].s == i - 1);
		cnt = 0;
		x = a[i].s;
		while (x > 0)
		{
			if (x % 2)
			{
				cnt++;
				//t[cnt]++;
			}
			x /= 2;
		}
		a[i].c = cnt;
	}
	f = 1;
	h = n;
	while (h > 0)
	{
		if (h % 2 && h != 1)
		{
			f = 0;
			break;
		}
		h /= 2;
	}
	if (p && f)
	{
		cnt = 0;
		while (m > 0)
		{
			m /= 2;
			cnt++;
		}
		q = 1;
		for (int i = 1; i <= cnt - 1; i++)
		{
			q *= 2;
		}
		cout << a[n].s - q + 1;
		return 0;
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		if (t[a[i].c] >= m)
		{
			a[i].g = 1;
		}
		else
		{
			a[i].g = 0;
		}
	}*/
	sort(a + 1, a + n + 1, cmp);
	ans = a[1].s;
	for (int i = 2; i <= m; i++)
	{
		ans = ans & a[i].s;
	}
	cout << ans;
	return 0;
}