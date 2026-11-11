#include <bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long a[2000010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 2)
	{
		unsigned long long maxn = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i!=j)
				{
					maxn = max(a[i]&a[j],maxn);	
				}
			}
		}
		cout << maxn;
		return 0;
	}
	if(m==1)
	{
		unsigned long long maxn1 = 0;
		for(int i = 1;i <= n;i++)
		{
			maxn1 = max(maxn1,a[i]);
		}
		cout << maxn1;
		return 0;
	}
	if(m==n)
	{
		unsigned long long maxn2 = a[1];
		for(int i = 2;i <= n;i++)
		{
			maxn2 = maxn2 & a[i];
		}
		cout << maxn2;
		return 0;
	}
	if(m==n-1)
	{
		unsigned long long maxn3 = 0;
		for(int i = 1;i <= n;i++)
		{
			unsigned long long cnt = a[i+1];
			for(int j = 1;j <= n;j++)
			{
				if(i!=j&&j!=i+1)
				{
					cnt = cnt&a[j];
				}
			}
			maxn3 = max(maxn3,cnt);
		}
		cout << maxn3;
		return 0;
	}
	return 0;
}