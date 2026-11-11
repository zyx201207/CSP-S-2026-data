#include <bits/stdc++.h>
using namespace std;
long long n,m,num[200005],dp[2005][2005],ans;
long long read()
{
	char c = getchar();
	long long res = 0,x = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			x = -1;	
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * x;
} 
void wr(long long x)
{
	if (x >= 10)
	{
		wr(x / 10);	
	}
	putchar(x % 10 + '0');
	return ;
}
void write(long long x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}	
	wr(x);
	return ;
} 

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n = read();
	m = read();
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	for (int i = 1;i <= n;i++)
	{
		num[i] = read();
		dp[0][i] = 0;
		dp[i][0] = 1073741823;
	}
	dp[1][1] = num[1];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= min(n,m);j++)
		{
			if (i == 1 && j == 1)
			{
				continue ;
			}
			dp[i][j] = max(dp[i - 1][j - 1] & num[i],dp[i - 1][j]);
		}
	}
	for (int i = m;i <= n;i++)
	{
		ans = max(ans,dp[i][m]);
	}
	cout << ans;
	return 0;
}

