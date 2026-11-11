#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct path_item
{
	int x;
	int alt_cnt;
};

const int N = 2e6 + 8;
int _cid;
int n;
ll d;
ll a[N];

bool edge(int x, int y)
{
	return abs(a[y] - a[x]) <= d;
}

int get_alt(int x, int y, int z)
{
	if (!(
		(y - 1  > x) && edge(y - 1, z)
	))
		return 0;
	if (!(
		(y - 2 > x) && edge(y - 2, z)
	))
		return 1;
	return 2;
};

namespace bf
{

void solve()
{
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	vector<path_item> p;
	ll ans = 0;
	for (int u = 1; u <= n; u++)
	{
		int alt_sum = 0;
		auto update_alt = [&]() -> void
		{
			if (p.size() <= 2)
				return;
			alt_sum -= p[p.size() - 2].alt_cnt;
			int new_alt_cnt = get_alt(p[p.size() - 3].x, p[p.size() - 2].x, p[p.size() - 1].x);
			p[p.size() - 2].alt_cnt = new_alt_cnt;
			alt_sum += new_alt_cnt;
		};
		p.clear();
		p.push_back({u, 0});
		for (int v = u + 1; v <= n; v++)
		{
			if (!edge(v - 1, v))
				break;
			if (p.size() >= 2 && edge(p[p.size() - 2].x, v))
				p.pop_back();
			p.push_back({v, 0});
			update_alt();
			if (alt_sum == 1)
			{
				ans++;
				#ifdef DEBUG
				// fprintf(stderr, "%d %d\n", u, v);
				#endif
			}
		}
	}
	printf("%lld\n", ans);
}

}

namespace sqB
{

int find_rightmost_linked(int x)
{
	int l = x, r = n;
	while (l <= r)
	{
		const int mid = (l + r) >> 1;
		if (edge(x, mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}

int find_leftmost_2(int x, int y)
{
	int l = y + 1, r = n;
	while (l <= r)
	{
		const int mid = (l + r) >> 1;
		if (edge(y, mid) && get_alt(x, y, mid) >= 2)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

int find_leftmost_lt2(int x, int y)
{
	int l = y + 1, r = n;
	while (l <= r)
	{
		const int mid = (l + r) >> 1;
		if (edge(y, mid) && get_alt(x, y, mid) >= 1)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

void solve()
{
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	ll ans = 0;
	for (int x = 1; x <= n; x++)
	{
		int y = find_rightmost_linked(x);
		if (y == n)
			continue;
		int zleft = find_leftmost_2(x, y);
		int zright = find_leftmost_lt2(x, y);
		ans += zright - zleft;
	}
	printf("%lld\n", ans);
}

}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T;
	scanf("%d%d", &_cid, &T);
	while (T--)
	{
		if (13 <= _cid && _cid <= 14)
			sqB::solve();
		else
			bf::solve();
	}
	return 0;
}