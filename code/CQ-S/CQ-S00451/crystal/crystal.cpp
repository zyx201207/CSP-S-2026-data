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
	const ll N = 5e5;
	ll a[N + 5];
	int main()
	{
		ll n = read(), m = read();
		for (ll i = 1; i <= n; i ++ ) a[i] = read();
		std :: sort(a + 1, a + n + 1);
		ll res = 0;
		for (ll r = 1, l = 1, sum = 0; r <= n; r ++ )
		{
			while (sum > m) sum -= a[r] - a[l], l ++ ;
			res = std :: max(res, r - l + 1);
			sum += (r - l + 1) * (a[r + 1] - a[r]);
		}
		printf("%lld\n", res);
		return 0;
	}
}
int main()
{
#ifdef LOCAL
	// freopen("in.txt", "r", stdin);
	// freopen("crystal2.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	int T = 1;
	while (T -- ) MYJBCHX :: main();
	fprintf(stderr, "%.2lfs\n", std :: clock() / 1000.0);
	return 0;
}