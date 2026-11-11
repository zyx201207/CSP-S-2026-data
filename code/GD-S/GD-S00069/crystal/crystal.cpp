#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[500005];
long long x[500005];
long long m,sum,ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		long long j = 1;
		for (j = 1;j <= n;j++)
		{
			x[j] = abs(a[j] - a[i]);
		}
		sort(x + 1,x + n + 1);
		sum = 0;
		for (j = 1;j <= n;j++)
		{
			sum += x[j];
			if (sum > m)
			{
				break;
			}
		}

		ans = max(ans,j - 1);
	}
	cout << ans;
	
	
	
	
	
	
	
	return 0;
}
