#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000003],cnt,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if(c == 11 or c == 12)
		{
			long long x = a[2] - a[1];
			if((x * 2 - 1) >= d)
			{
				cout << 0;
			}
			else
			{
				cout << max(n - (d / x * 2 - 1),0ll); 
			}
			cout << '\n';
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 3;j <= n;j++)
			{
				if((a[j] - a[i]) >= 2 * d)
				{
					break;
				}
				if(a[j] - a[i] > d)
				{
					cnt = 0;
					bool f = 0;
					for(int k = i + 1;k < j;k++)
					{
						if(a[k] + d >= a[j] and a[k] - d <= a[i])
						{
							cnt++;
						}
						if(cnt > 2)
						{
							f = 1;
							break;
						}
					}
					if(cnt == 2 and f == 0)
					{
						ans++;
					}	
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
