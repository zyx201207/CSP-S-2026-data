#include<bits/stdc++.h>

using namespace std;

int n , m , a[5005];
int cnt[20005][20005];
int ans = INT_MIN;
long long b;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d" , &n , &m);
	bool f_A = 1;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d" , &a[i]);
		if(a[i] != i)
		{
			f_A = 0;
		}
	}
	if(f_A)
	{
		long long p = 1 , cnt = 0;
		while(m >= a[p])
		{
			m -= a[p ++];
			cnt ++;
		}
		cout << cnt + 1;
		return 0;
	}
	stable_sort(a + 1 , a + n + 1);
	if(n <= 5000)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(i == 1)
				{
					cnt[1][j] = a[j] - a[1];
					continue;
				}
				cnt[i][j] = cnt[i - 1][j] - cnt[i - 1][i];
			}
		}
		for(int i = 2;i <= n;i++)
		{
			int k = m , num = 0;
			for(int j = 1;j < i;j++)
			{
				if(k >= cnt[j][i])
				{
					k -= cnt[j][i];
					num ++;
				}
				ans = max(ans , num + 1);
			}
		}
		cout << ans;
		return 0;
	}
	else 
	{
		b = a[n] - a[n - 1];
		if(b == 0)
		{
			cout << n;
			return 0;
		}
		long long l = 1;
		while(m >= l * b)
		{
			m -= l * b;
			ans ++;
		}
		cout << ans + 1;
		return 0;
	}
	return 0;	
} 
