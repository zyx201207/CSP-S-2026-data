#include<bits/stdc++.h>
using namespace std;

int n, m;
long long a[200010], dp[200010], ans;
bool cok = true, aok = true, bok = true;
void dfs(int x, int cnt, long long c)
{
	if(cnt == m)
	{
		ans = max(c, ans);
		return;
	}
	for(int i = x + 1;i <= n + 1 - (m - cnt);i++)
	{
		if(cnt == 0)
		{
			dfs(i, 1, a[i]);
		}
		else
		{
			dfs(i, cnt + 1, c & a[i]);
		}
	}
	return;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld", &a[i]);
		if(a[i] >= 4)
		{
			cok = false;
		}
		if(a[i] != i - 1)
		{
			bok = false;
		}
		if(aok)
		{
			int aaa = a[i] + 1;
			while(aaa > 0)
			{
				if(aaa % 2 == 1)
				{
					aok = false;
					break;
				}
				aaa/=2;
			}
		}
	}
	if(aok)
	{
		sort(a + 1, a + n + 1);
		ans = a[n];
		for(int i = n - 1;i > n - m;i++)
		{
			ans &= a[i];
		}
		printf("%lld", ans);
		return 0;
	}
	if(cok)
	{
		int cnt[4] = {0, 0, 0, 0};
		for(int i = 1;i <= n;i++)
		{
			cnt[a[i]]++;
		}
		if(cnt[3] >= m)
		{
			printf("3");
			return 0;
		}
		if(cnt[2] + cnt[3] >= m)
		{
			printf("2");
			return 0;
		}
		if(cnt[1] + cnt[3] >= m)
		{
			printf("1");
			return 0;
		}
		printf("0");
		return 0;
	}
	if(bok)
	{
		ans = n - 1;
		for(int i = n - 2;i >= n - m;i--)
		{
			ans &= i;
		}
		printf("%lld", ans);
		return 0;
	}
	if(m == 1)
	{
		long long mx = -1;
		for(int i = 1;i <= n;i++)
		{
			mx = max(mx, a[i]);
		}
		printf("%lld", mx);
		return 0;
	}
	if(m == n)
	{
		ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans &= a[i];
		}
		printf("%lld", ans);
		return 0;
	}
	if(m == n - 1 && n > 2000)
	{
		long long mn = (1LL << 60);
		int ii;
		for(int i = 2;i <= n;i++)
		{
			if((a[i] & a[i - 1]) < mn)
			{
				mn = a[i] - a[i - 1];
				ii = i;
			}
		}
		if(ii != 1)
		{
			ans = a[1];
			for(int i = 2;i <= n;i++)
			{
				if(i == ii)
				{
					continue;
				}
				ans &= a[i];
			}
		}
		else
		{
			ans = a[2];
			for(int i = 3;i <= n;i++)
			{
				ans &= a[i];
			}			
		}
		printf("%lld", ans);
	}
	dfs(0, 0, 0);
	printf("%lld", ans);
	return 0;
}
