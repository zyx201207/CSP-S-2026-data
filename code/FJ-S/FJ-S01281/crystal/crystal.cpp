#include <iostream>
#include <algorithm>

namespace preFile
{
	void init()
	{
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

typedef long long ll;
const int maxn = 5e5 + 3;
int n, ans;
ll m, a[maxn], s[maxn];

int calc(int p)
{
	int l = 0, r = p - 1, ret = 0;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (a[p] * mid - s[p - 1] + s[p - mid - 1] <= m) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ret;
}

int main()
{
	preFile::init();
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i], ans = std::max(ans, calc(i) + 1);
	std::cout << ans;
	return 0;
}
