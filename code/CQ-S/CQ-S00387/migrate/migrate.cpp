#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, T, n, d, s, a[2000005];
struct e{
	int x, y, z, d;
}f[10000005];
void build(int x, int l, int r)
{
	f[x].x = l;
	f[x].y = r;
	f[x].z = 0;
	f[x].d = 1;
	if (l == r)
	{
		return ;
	}
	int mid = l + (r - l) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	f[x].z = min(f[x << 1].z, f[x << 1 | 1].z);
	f[x].d = min(3ll, (f[x].z == f[x << 1].z) * f[x << 1].d + (f[x].z == f[x << 1 | 1].z) * f[x << 1 | 1].d);
}
void change(int x, int p, int z, int w)
{
	if (f[x].x > p || f[x].y < p)
	{
		return ;
	}
	if (f[x].x == f[x].y)
	{
		f[x].z = z;
		f[x].d = w;
		return ;
	}
	change(x << 1, p, z, w);
	change(x << 1 | 1, p, z, w);
	f[x].z = min(f[x << 1].z, f[x << 1 | 1].z);
	f[x].d = min(3ll, (f[x].z == f[x << 1].z) * f[x << 1].d + (f[x].z == f[x << 1 | 1].z) * f[x << 1 | 1].d);
}
pair<int, int> ask(int x, int l, int r)
{
	if (f[x].x > r || f[x].y < l)
	{
		return {INT_MAX, 0};
	}
	if (f[x].x >= l && f[x].y <= r)
	{
		return {f[x].z, f[x].d};
	}
	pair<int, int> u = ask(x << 1, l, r), v = ask(x << 1 | 1, l, r), h;
	h.first = min(u.first, v.first);
	h.second = min(3ll, (u.first == h.first) * u.second + (v.first == h.first) * v.second);
	return h;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		s = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			build(1, 1, n);
			change(1, i, 0, 1);
			int l = i;
			for (int j = i + 1; j <= n; j++)
			{
				while (a[l] < a[j] - d)
				{
					l++;
				}
				if (l == j)
				{
					break;
				}
				pair<int, int> h = ask(1, l, j - 1);
				if (h.second == 2)
				{
					s++;
				}
				change(1, j, h.first + 1, h.second);
			}
		}
		cout << s << "\n";
	}
	return 0;
} 
