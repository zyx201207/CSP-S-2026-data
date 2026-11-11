#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
int n , m , d , q , a [N] , k , c [510] [1010], len , x , y;
vector <pair <int , int> >g [N];
bool vis [N];
signed main()
{
		freopen ("subway.in" , "r" , stdin);
		freopen ("subway.out" , "w" , stdout);
		cin >> n >> n >> m >> d >> q;
		memset (c , INF , sizeof (c));
		for (int i = 1; i <= n; i++) c [i] [i] = 0;
		for (int i = 1; i <= m; i++) scanf ("%lld" , &a [i]);
		int sum = m;
		for (int i = 1; i <= n; i++)
		{
			cin >> k;
			for (int j = 1; j <= k; j++)
			{
				cin >> x >> y;
				if (vis [x])
					for (int l = 1; l < i; l--)
						c [l] [i] = c [i] [l] = min (c [i] [l] , c [l] [l + n] + y);
				c [i] [i + n] = y;
				vis [x] = 1;
			}	
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					c [i] [j] = min (c [i] [j] , c [i] [k] + c [k] [j]);
		while ( q-- )
		{
			cin >> x >> y;
			int sum = 0;
			sum += a [x] , sum += a [y];
			cout << sum + c [x] [y] << "\n";
		}
		return 0;
}

