#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
long long c, t, n, d, x[N], dp[N], mn[N];  

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> c >> t;
	while(t--)
	{
		bool pf = true;
		cin >> n >> d;
		long long ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >> x[i];
		}
		if(d >= x[n] - x[1])
		{
			cout << 0 << "\n";
			continue;
		}
		for(int l = 1; l < n; l ++)
		{
			for(int r = l + 1; r <= n; r ++)
			{		
				for(int i = l; i <= r; i ++)
				{
					dp[i] = 0;
					mn[i] = 1e18;
				}
				dp[l] = 1;
				mn[l] = 0;
				for(int i = l; i <= r; i ++)
				{
					for(int j = i - 1; j >= l; j --)
					{
						if(x[i] - x[j] <= d)
						{
							if(mn[i] > mn[j] + 1)
							{
								mn[i] = mn[j] + 1;
								dp[i] = dp[j]; 
							}
							else if(mn[i] == mn[j] + 1)
							{
								dp[i] += dp[j]; 
							}
						}
					}
				}
		//		cerr << l << " " << r << " " << dp[r] << "\n";
				if(dp[r] == 2)
				{
					ans ++;
				}
			}
		}
		cout << ans << "\n"; 
	}
	
}
