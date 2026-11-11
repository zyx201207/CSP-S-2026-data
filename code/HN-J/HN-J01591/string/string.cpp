#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 5;
long long p[N], a[N];
char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
		if (c[i] == c[i - 1])//合并区间	 
		{
			a[i - 1] += a[i];
			i --;
			n --;
		}
		p[i] = p[i - 1] + a[i];
	}
	
	long long mid = (p[n] + 1) / 2; //找到中间的值 
	long long idx = 0; //mid位于的区间 
	for (long long i = 1; i <= n; i ++) //找mid位于的区间
	{
		if (mid <= p[i])
		{
			idx = i;//标记位置 
			break;
		}
	}
	
	long long ans = 0, m = 0;
	
	if (p[n] % 2 == 0) m = mid - p[idx - 1];
	else m = mid - p[idx - 1] - 1;
	
	long long l = idx - 1, r = idx + 1;
	if (m > p[idx] - mid) //处理区间idx的更改次数 
	{
		long long k = m - p[idx] + mid;
		for(long long i = idx + 1;i <= n;)
		{
			if(c[i] == c[idx])
			{
				if(a[i] > k)
				{
					a[i] -= k;
					r = i;
					break;
				}
				else
				{
					k -= a[i];
				}
				i ++;
			}
			else
			{
				if(a[i] > k)
				{
					ans += k;
					a[i] -= k;
					r = i;
					break;
				}
				else
				{
					ans += a[i];
					k -= a[i];
					a[i] = 0;
					i ++;
				}
			}
		}
	}
	else
	{
		long long k = p[idx] - mid - m;
		for(long long i = idx - 1;i >= 1;)
		{
			if(c[i] == c[idx])
			{
				if(a[i] > k)
				{
					a[i] -= k;
					l = i;
					break;
				}
				else
				{
					k -= a[i];
				}
				i --;
			}
			else
			{
				if(a[i] > k)
				{
					ans += k;
					a[i] -= k;
					l = i;
					break;
				}
				else
				{
					ans += a[i];
					k -= a[i];
					a[i] = 0;
					i --;
				}
			}
		}
	}
	
	for (long long i = l, j = r; i >= 1 && j <= n;)
	{
		if (c[i] == c[j])
		{
			if (a[i] > a[j])
			{
				long long k = a[i] - a[j];
				ans += k;
				a[i] -= k;
				j ++;
			}
			else 
			{
				long long k = a[j] - a[i];
				ans += k;
				a[j] -= k;
				i --;
			}
		}
		else
		{
			if (a[i] > a[j])
			{
				ans += a[j];
				a[i] -= a[j];
				j ++;
			}
			else 
			{
				ans += a[i];
				a[j] -= a[i];
				i --;
			}
		}
	}
	cout << ans;
	return 0;
} 
