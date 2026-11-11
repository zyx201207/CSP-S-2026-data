#include <bits/stdc++.h>
#define vc(i, j, k) for (int i(j), vc##i(k + 1); i < vc##i; ++i)
#define cv(i, j, k) for (int i(j), vc##i(k - 1); i > vc##i; --i)
using ll = long long;
using pii = std::pair<int, int>;

ll read()
{
	ll x = 0; bool f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f = ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1ll) + (x << 3ll) + (ch ^ '0'), ch = getchar();
	if (f) x = ~x + 1;
	return x;
}

const int N = 500000 + 5;
int n; ll k;
ll a[N];

int find(ll x)
{
	int l = 1, r = n, ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] <= x) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return ans;
}

bool check(int mid)
{
	ll l = -1e18, r = 1e18;
	while (l <= r)
	{
		ll md = (l + r) >> 1ll, g = k;
		int p = find(md);
		int count = 0, neg = n - p;
		cv(i, p, 1)
		{
			if (g < md - a[i]) break;
			g -= (md - a[i]), ++count;
		}
		if (count >= mid) return true;
		if (neg + mid > n) l = md + 1;
		else r = md - 1;
	}
	return false;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), k = read();
	vc(i, 1, n) a[i] = read() + 1e12;
	std::sort(a + 1, a + 1 + n, std::less<int>());
	int l = 1, r = n, ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	std::cout << ans << '\n';
} 
