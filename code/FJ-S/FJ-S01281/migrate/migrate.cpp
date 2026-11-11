#include <iostream>
#include <algorithm>

namespace preFile
{
	void init()
	{
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

typedef long long ll;
const int maxn = 2e6 + 3;
int n;
ll d, a[maxn];

namespace B
{
	void Main()
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (a[i] - a[1] <= d && a[n] - a[i] <= d) cnt++;
		if (cnt != 2) return std::cout << "0\n", void();
		ll ans = 0;
		for (int i = 1; i <= n; i++) ans += n - (std::upper_bound(a + 1, a + n + 1, a[i] + d) - a);
		std::cout << ans << '\n';
	}
}

void solve(int c)
{
	std::cin >> n >> d;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	if (c == 13 || c == 14) return B::Main();
	
}

int main()
{
	preFile::init();
	int c, t; std::cin >> c >> t;
	while (t--) solve(c);
	return 0;
}
