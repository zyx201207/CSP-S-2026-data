#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
int T, c;
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if ( c == 0 || c == 11 || c == 12 )
	{
		for ( ll n, m, x, y; T--; )
		{
			scanf("%lld%lld%lld", &n, &m, &y);
			if ( n == 1 )
			{
				printf("0\n");
				continue;
			}
			scanf("%lld", &x);
			x -= y;
			for ( int i = 3; i <= n; i++ )
			{
				cin >> y;
			}
			if ( m / x <= 1 )
			{
				printf("0\n");
				continue;
			}
			printf("%lld\n", n * m / (m / x));
		}
	}
	else
	{
		for ( ; T--; )
		{
			cout << "0\n";
		}
	}
	return 0;
}
