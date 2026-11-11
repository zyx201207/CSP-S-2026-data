#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],ans[500005],m,m1,maxn=0,sum=0;
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	m1 = m;
	for (int i=1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	if (n > 5000 && m > 100000000)
	{
		for (int i=2; i <= n; i++)
		{
			if (m - (a[i]-a[i-1])*(i-1) >= 0)
			{
				m -= (a[i]-a[i-1])*(i-1);
				for (int j=1; j <= i-1; j++)
				{
					a[j] = a[i];
				}
			}
			else
			{
				cout << i-1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	int maxn=0;
	for (int k=2; k <= n; k++)
	{
		m = m1;
		for (int i=1; i <= n; i++)
		{
			a[i] = b[i];
		}
		int f=0;
		for (int i=k; i <= n; i++)
		{
			if (m - (a[i]-a[i-1])*(i-k+1) >= 0)
			{
				m -= (a[i]-a[i-1])*(i-k+1);
				for (int j=k-1; j <= i; j++)
				{
					a[j] = a[i];
				}
			}
			else
			{
				f=1;
				maxn = max(maxn,i-k+1);
				break;
			}
		}
		if (!f)
		{
			maxn = max(maxn,n-k+2);
		}
	}
	cout << maxn;
	return 0;
}
