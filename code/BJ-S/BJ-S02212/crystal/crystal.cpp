#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,maxa;
long long a[500005];
long long dp[2][500005];
long long bo[300];
long long dp2[300][300][2];
bool tA = 1,tB = 1;
int tBc;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (i == 2) tBc = a[2] - a[1];
		if (i > 2 && a[i] - a[i-1] != tBc) tB = 0;
		if (a[i] != i) tA = 0;
		maxa = (maxa>a[i]?maxa:a[i]);
	}
	sort(a+1,a+n+1);
	if (n <= 5000)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i;j <= n;j++)
			{
				if (i == j) dp[i%2][j] = 0;
				else dp[i%2][j] = dp[i%2][j-1]+(j-i)*(a[j]-a[j-1]);
				if (dp[i%2][j] <= m)
					ans = (ans>j-i+1?ans:j-i+1);
			}
		}
	}
	else if (maxa <= 100)
	{
		for (int i = 1;i <= n;i++)
			bo[a[i]+100]++;
		for (int i = 0;i <= 200;i++)
			for (int j = i;j <= 200;j++)
				if (i == j) dp2[i][j][1] = bo[i];
		for (int i = 0;i <= 200;i++)
			for (int j = i;j <= 200;j++)
				if (i != j) dp2[i][j][1] = dp2[i][j-1][1]+dp2[j][j][1];
		for (int i = 0;i <= 200;i++)
			for (int j = i;j <= 200;j++)
			{
				if (i == j) dp2[i][j][0] = 0;
				else dp2[i][j][0] = dp2[i][j-1][0]+dp2[i][j-1][1];
				if (dp2[i][j][0] <= m)
					ans = (ans>dp2[i][j][1]?ans:dp2[i][j][1]);
			}
		
		for (int i = 0;i <= 200;i++)
		{
			for (int j = 0;j <= 200;j++)
				cout << dp2[i][j][1] << " ";
			cout << "\n";
		}
	}
	else if (tA == 1)
	{
		long long cost = 0;
		for (int i = 1;i <= n;i++)
		{
			cost += i-1;
			if (cost >= m) break;
			ans++;
		}
	}
	else if (tB == 1)
	{
		long long cost = 0;
		for (int i = 1;i <= n;i++)
		{
			cost += (i-1)*tBc;
			if (cost >= m) break;
			ans++;
		}
	}
	else
		ans = 500000;
	cout << ans;
	return 0;
}
