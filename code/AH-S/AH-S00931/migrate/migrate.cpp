#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,x[2000005],d,c,t,dp[5005][5005],num,ans;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		for(int i = 1; i <= n-2; i++)
		{
			for(int j = 3; j <= n; j++)
			{
					if(x[j] - x[i] <= d)
					{
						if(x[j]-x[i] <= dp[i][j])
							{dp[i][j] = x[j] - x[i];
							num++;}
					}
					else
						break;
				if(num == 2)
					ans++;
			}
		}
		cout << num <<"\n";
		memset(x,0,sizeof(x)); num = 0; ans = 0;
	}
	return 0;
}
