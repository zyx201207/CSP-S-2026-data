#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,maxx,pd,mun,cj;
long long a[500005];
long long b[500005];
long long c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	if(n > 5000)
	{
		cj = a[2] - a[1];
		for(int i = 1;i <= 500005;i++)
		{
			ans = ans + cj * i;
			mun++;
			if(ans > m)
			{
				break;
			}
		}
		cout << min(mun - 1,n);
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		b[i] = a[i+1] - a[i];
	}
	b[n] = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			ans = ans + b[j - 1] * (j - i);
			mun++;
			if(ans > m)
			{
				maxx = max(maxx,mun - 1);
				ans = 0;
				mun = 0;
				break;
			}
			else if(j == n)
			{
				maxx = max(maxx,mun);
				ans = 0;
				mun = 0;
				pd = 1;
				break;
			}
		}
		if(pd)
		{
			break;
		}
	}
	cout << maxx;
	return 0;
}
