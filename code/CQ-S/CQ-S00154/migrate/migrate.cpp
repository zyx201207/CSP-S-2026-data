#include <iostream>
#include <cstring>
using namespace std;
int a[100010],dp[510][510][510];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t --)
	{
		cout << "!!!";
		int n,d,cnt = 0;
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> a[i];
		}
		dp[1][1][0] = 1;
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = i + 1 ; j <= n ; j ++)
			{
				for(int o = 1 ; o <= n ; o ++)
				{
					int k = j - 1;
					while(a[j] - a[k] <= d)
					{
						k --;
					}
					k ++;
					for(int l = k ; l <= j - 1 ; l ++)
					{
						dp[i][j][o] += dp[i][l][o - 1];
					}
				}
			}
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				for(int k = 1 ; k <= n ; k ++)
				{
					if(dp[i][j][k] != 0)
					{
						if(dp[i][j][k] == 2)
						{
							cnt ++;
						}
						break;
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
//dp[i][j][k]表示从a[i]~a[j],花k步的方法数
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
