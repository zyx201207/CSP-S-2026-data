#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],q[500005];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n==1)
	{
		cout << 1;
		return 0;
	}
	long long p = a[2] - a[1];
	bool flag = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i]-a[i-1]!=p)
		{
			flag = 0;
		}
	}
	if(flag == 1)
	{
		long long q = 0;
		for(int i = 1; i <= n; i++)
		{
			if(m>=q)
			{
				ans = i;
			}
			else
			{
				break;
			}
			q += p * i;
		}
		cout << ans;
		return 0;
	}
	for(int i = 2; i <= n; i++)
	{
		c[i] = a[i] - a[i-1];
	}
	for(int i = 2; i <= n; i++)
	{
		q[i] = q[i-1] + c[i] * (i-1);
	}
	ans = 1;
	for(int i = 2; i <= n; i++)
	{
		int k = 1;
		while(m<q[i])
		{
			q[i] -= (a[i] - a[k]);
			k++;
		}
		ans = max(ans,i-k+1);
	}
	cout << ans;
	return 0;
}
