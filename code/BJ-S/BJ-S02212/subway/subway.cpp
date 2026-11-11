#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[500005],x,y,ans;
long long w[500005];
struct tr
{
	int w;
	int t[1005];
}wa[1005];
int a[1005],t[1005][1005];
long long dp[1005][1005];
int b[1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 0;i <= 1001;i++)
		for (int j = 0;j <= 1001;j++)
			dp[i][j] = 100;
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			cin >> a[j] >> t[i][j];
		}
		for (int j = 1;j <= k[i];j++)
		{
			for (int g = j+1;g <= k[i];g++)
			{
				b[a[j]]++;
				b[a[g]]++;
				wa[a[j]].w++;
				wa[a[g]].w++;
				wa[a[j]].t[b[a[j]]] = a[g];
				wa[a[g]].t[b[a[g]]] = a[j];
				dp[a[j]][a[g]] = t[i][j] + t[i][g];
				dp[a[g]][a[j]] = t[i][j] + t[i][g];
			}
		}
	}
	for (int cnt = 1;cnt <= d;cnt++)
		for (int i = 1;i <= m;i++)
			for (int j = 1;j <= m;j++)
			{
				if (i == j) dp[i][j] = 0;
				else
				{
					for (int g = 1;g <= wa[i].w;g++)
						dp[i][j] = min(dp[i][j],dp[i][wa[i].t[g]]+dp[wa[i].t[g]][j]);
				}
			}
	while (q--)
	{
		cin >> x >> y;
		cout << dp[x][y]+w[x]+w[y] << "\n";
	}
	return 0;
}
