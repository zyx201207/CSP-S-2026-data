#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
inline ll read() {ll x; return scanf("%lld", &x), x;}
namespace MYJBCHX
{
	const int N = 1e6;
	int n;
	ll d;
	ll x[N + 5];
	int dp[N + 5], cnt[N + 5];
	inline int calc(int l, int r)
	{
		dp[l] = 0, cnt[l] = 1;
		for (int i = l + 1; i <= r; i ++ )
		{
			dp[i] = 10000, cnt[i] = 1;
			for (int j = i - 1; j >= l; j -- )
			{
				if (x[i] - x[j] > d) break;
				if (dp[i] > dp[j] + 1) dp[i] = dp[j] + 1, cnt[i] = 0;
				cnt[i] += (dp[i] == dp[j] + 1) * cnt[j];
				cnt[i] = std :: min(cnt[i], 3);
			}
		}
		return dp[r] <= N ? cnt[r] : 0;
	}
	int main()
	{
		n = read(), d = read();
		for (int i = 1; i <= n; i ++ ) x[i] = read();
		if (n > 300)
		{
			if (d / (x[2] - x[1]) != 2) puts("0");
			else printf("%d\n", n - 3);
			return 0;
		}
		int res = 0;
		for (int i = 1; i <= n; i ++ )
			for (int j = i + 1; j <= n; j ++ )
				if (calc(i, j) == 2) res ++ ;
		printf("%d\n", res);
		return 0;
	}
}
int main()
{
#ifdef LOCAL
	// freopen("in.txt", "r", stdin);
	freopen("migrate4.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	read(); int T = read();
	while (T -- ) MYJBCHX :: main();
	fprintf(stderr, "%.2lfs\n", std :: clock() / 1000.0);
	return 0;
}