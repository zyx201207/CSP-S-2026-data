#include <cstdio>
#include <algorithm>
using std::max;
#define maxx(A, B) (A = max(A, B))
typedef long long intt;

const int MX = 500010;

intt a[MX];

namespace solve
{
intt pre[MX];

bool query(int l, int r, intt m)
{
	return a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) <= m;
}

int lower(int i, intt m)
{
	int l = 1, r = i, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (query(mid, i, m))
			r = mid;
		else l = mid + 1;
	}
	return l;
}


int solve(int n, intt m)
{
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; pre[i] = pre[i - 1] + a[i], i++);
	int ret = 0;
	for (int i = 1; i <= n; i++)
		maxx(ret, i - lower(i, m) + 1);
	return ret;
}
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	intt m;
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; scanf("%lld", a + i++));
	printf("%d", solve::solve(n, m));
}