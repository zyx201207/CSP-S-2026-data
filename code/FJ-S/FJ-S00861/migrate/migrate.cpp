#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int dis[2000005];
int dp[2005][2005];
int minn[2005][2005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{	memset(minn,63,sizeof(minn));
		memset(dis,0,sizeof(dis));
		memset(dp,0,sizeof(dp));
		int ans = 0;
		int n,d;
		cin>>n>>d;
		for(int i = 1 ; i <= n ; i ++) cin>>dis[i];
		sort(dis+1,dis+1+n);
		for(int i = 1 ;i <= n ; i ++)
		{
			for(int j = i ; j <= n ; j ++)
			{
				if(i == j)
				{
					dp[i][j] = 1;
					minn[i][j] = 0;
				}
				else
				{
					int min_dis = 1e9 + 7;
					for(int k = lower_bound(dis+1,dis+1+n,dis[j] - d) - dis ; k <= j-1 ; k ++)
					{
						if(min_dis > minn[i][k])
						{
							dp[i][j] = dp[i][k];
							min_dis = minn[i][k];
						}
						else if(minn[i][k] == min_dis)
						{
							dp[i][j] += dp[i][k];
						}
					}
					minn[i][j] = min_dis + 1;
				}
				if(dp[i][j] == 2) ans ++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
