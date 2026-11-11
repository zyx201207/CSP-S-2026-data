#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int n, d, t, cc;
int a[N], sum[N];
int f[5005][5005], c[5005][5005];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> cc >> t;
	while(t -- ) 
	{
		scanf("%lld%lld", &n, &d);
		bool flag = 1;
		int s = 0;
		for(int i = 1; i <= n; i ++ )
		{
			scanf("%lld", &a[i]); 
			if(i > 2)
			{
				if(a[i] - a[i - 1] != s)
					flag = 0;
			}
			else if(i == 2)
				s = a[2] - a[1];
		}
		if(flag)
		{
			if(s == 0)
				puts("0");
			else
			{
				int k = d / s;
				if(k <= 1 || n <= (2 * k - 1))
					puts("0");
				else
					cout << n - (2 * k - 1) << '\n';
			}
		}
		else
		{
			for(int i = 1; i <= n; i ++ )
				for(int j = 1; j <= n; j ++ )
					f[i][j] = 1e18, c[i][j] = 0;
			for(int i = 1; i <= n; i ++ )
			{
				f[i][i] = 0;
				if(i < n && a[i + 1] - a[i] <= d)
					f[i + 1][i] = 1;
			}
			c[1][1] = 1;
			int ans = 0;
			for(int i = 1; i <= n; i ++ )
			{
				for(int j = i - 1; j >= 1; j -- )
					for(int k = i - 1; k >= j && a[i] - a[k] <= d; k -- )
					{
						if(f[k][j] + 1 < f[i][j])
							f[i][j] = f[k][j] + 1, c[i][j] = c[k][j];
						else if(f[k][j] + 1 == f[i][j])	
							c[i][j] += c[k][j];
					}
				c[i][i] = 1;
			}
			for(int i = 1; i <= n; i ++ )
				for(int j = 1; j <= i; j ++ )
				{
					if(c[i][j] == 2)
						ans ++ ;
				}
			cout << ans << '\n';
		}
	}
	return 0;				
}
