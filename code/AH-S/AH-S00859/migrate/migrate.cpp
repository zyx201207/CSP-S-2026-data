#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL c, t, n;
LL m, a[2000005], dp[505][505]; 
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --)
	{
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= n; i ++)
			scanf("%lld", &a[i]);
		LL ans = 0;
		for(int i = 1; i < n; i ++)
		{
			if(a[i + 1] - a[i] <= m)
				dp[i][i + 1] = 1;
			else
				dp[i][i + 1] = 0;
		}
		for(int i = 1; i <= n; i ++)
		{
			for(int j = i + 2; j <= n; j ++)
			{
				for(int k = j - m; k >= i; k --)
				{
					if(a[j] - a[k] <= m)
						dp[i][j] += dp[i][k];
				}
				if(dp[i][j] == 2)
					ans ++;
			}
		}
//		for(int i = 1; i <= n; i ++)
//		{
//			for(int j = i + 1; j <= n; j ++)
//				cout << dp[i][j] << ' ';
//			cout << '\n';
//		}
		cout << ans << '\n'; 
	}
	return 0;
}

