#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long f[200010][2],dp[2010][2010];
int h[200010][2];
bool cmp(long long x,long long y)
{
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	if(n <= 2000)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j <= m;j++)
			{
				dp[i][j] = dp[i - 1][j];
				if(j >= 1)
				{
					long long k = (dp[i - 1][j - 1] & a[i]);
					if(dp[i - 1][j - 1] == 0)k = a[i];
					dp[i][j] = max(dp[i][j],k);
				}
			}
		}
		long long ret = 0;
		for(int i = 1;i <= n;i++)ret = max(ret,dp[i][m]);
		cout << ret;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		if((f[i - 1][1] & a[i]) > (f[i - 1][0] & a[i]))
		{
			f[i][1] = f[i - 1][1] & a[i];
			if(f[i - 1][1] == 0)f[i][1] = a[i];
			h[i][1] = h[i - 1][1] + 1;
		}
		else
		{
			f[i][1] = f[i - 1][0] & a[i];
			if(f[i - 1][0] == 0)f[i][1] = a[i];
			h[i][1] = h[i - 1][0] + 1;
			if((f[i - 1][1] & a[i]) == (f[i - 1][0] & a[i]))
			h[i][1] = max(h[i][1],h[i - 1][1] + 1);
		}
		if(f[i - 1][1] > f[i - 1][0])
		{
			f[i][0] = f[i - 1][1];
			h[i][0] = h[i - 1][1];
		} 
		else
		{
			f[i][0] = f[i - 1][0];
			h[i][0] = h[i - 1][0];
			if(f[i - 1][1] == f[i - 1][0])
			h[i][0] = max(h[i][0],h[i - 1][1]);
		}
	}
	long long ret = 0;
	for(int i = 1;i <= n;i++)
	{
		if(h[i][1] == m)ret = max(ret,f[i][1]);
		if(h[i][0] == m)ret = max(ret,f[i][0]);
	}
	cout << ret;
	return 0;
}
