#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;
int c,t,ans,cnt;
int ming = 2147483647;
long long m[2000005],mi[2000005];
bool book[20005][20005];
long long dp[5005][5005];
/*int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 0; i < t; i++)
	{
		ans = 0;
		int n,d;
		cin >> n >> d;
		for (int j = 0; j < n; j++)
		{
			cin >> m[j];
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = j; k < n; k++)
			{
				if(m[k]-m[j]<=d&&k!=j) book[j][k]=1;
				else book[j][k]=0;
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				dp[j][k]=book[j][k];
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = j; k < n; k++)
			{
				for(int w=j; w<k;w++)
				{
					dp[j][k]+=dp[j][w]*dp[w][k];
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if(dp[j][k]==2) ans++;
			}
		}
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}*/
void dfs(int x, int y, int d, int g)
{
	if(x==y)
	{
		if(g<ming)
		{
			ming=g;
			cnt=1;
		}else
		{
			if(g==ming)cnt++;
		}
		return;
	}


		for(int i = x + 1;i <= y;i++)
		{
			if(mi[i] - mi[x] <= d)
			{
				dfs(i,y,d,g+1);
			}
		}
		return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 0; i < t; i++)
	{
		ans = 0;
		int n,d;
		cin >> n >> d;
		for (int j = 0; j < n; j++)
		{
			cin >> m[j];
		}
		mi[0] = 0;
		for (int j = 1; j < n; j++)
		{
			mi[j] = mi[j-1] + m[j] - m[j-1];
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				ming = 2147483647;
				cnt=0;
				dfs(j,k,d,0);
				if(cnt == 2) ans++;
			}
		}
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}

