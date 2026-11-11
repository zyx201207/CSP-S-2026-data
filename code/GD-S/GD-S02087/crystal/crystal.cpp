#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int ans=0,num = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a+1+n);
	long long b[500005];
	long long c;
	for (int i = 1;i <= n;i++)
	{
		b[i] = a[n]-a[i];
		c += b[i];
		
	}
	if(c <= m)
	{
		cout << n;
		return 0;
	}
	if (m == 0)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (a[i] == a[j])
				{
					num++;
				}
				else
				{
					ans = max(num,ans);
					num=0;
					break;
				}
			}
		}
	}
	while(m > 0)
	{
		a[1]++;
		m--;
		sort(a + 1,a+1+n);
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (a[i] == a[j])
				{
					num++;
				}
				else
				{
					ans = max(num,ans);
					num=0;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
