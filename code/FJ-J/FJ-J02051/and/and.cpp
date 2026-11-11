#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans,t,num = 0x7fffffff,p[200010],q[200010];

bool in(int a)
{
	for(int i = 1;i <= m;i++) if(q[i] == a) return true;
	return false;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) scanf("%lld",p + i);
	sort(p + 1,p + n + 1);
	if(m == 1)
	{
		cout << p[n];
		return 0;
	}
	if(m == n)
	{
		for(int i = 1;i <= m;i++) num &= p[i];
		cout << num;
		return 0;
	}
	if(m == 2)
	{
		num = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j) continue;
				num = max(num,p[i] & p[j]);
			}
		}
		cout << num;
		return 0;
	}
	if(n <= 20)
	{
		if(m == 3)
		{
			num = 0;
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					for(int k = 1;k <= n;k++)
					{
						if(i == j || i == k || j == k) continue;
						num = max(num,p[i] & p[j] & p[k]);
					}
				}
			}
			cout << num;
			return 0;
		}
		if(m == 4)
		{
			num = 0;
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					for(int k = 1;k <= n;k++)
					{
						for(int h = 1;h <= n;h++)
						{
							if(i == j || i == k || j == k || i == h || j == h || k == h) continue;
							num = max(num,p[i] & p[j] & p[k] & p[h]);
						}
					}
				}
			}
			cout << num;
			return 0;
		}
		if(m == 5)
		{
			num = 0;
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					for(int k = 1;k <= n;k++)
					{
						for(int h = 1;h <= n;h++)
						{
							for(int l = 1;l <= n;l++)
							{
								if(i == j || i == k || j == k || i == h || j == h || k == h || i == l || j == l || k == l || h == l) continue;
								num = max(num,p[i] & p[j] & p[k] & p[h] & p[l]);
							}
						}
					}
				}
			}
			cout << num;
			return 0;
		}
	}
	for(int i = 1;i <= m;i++) num &= p[q[i]];
	cout << num;
	return 0;
}

