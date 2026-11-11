#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m == 1)
	{
		long long maxn = -1;
		for(int i = 1;i <= n;i++)
		{
			long long x;
			cin>>x;
			maxn = max(maxn,x);
		}
		cout<<maxn;
	}else if(m == 2)
	{
		long long maxn = -1;
		for(int i = 1;i <= n;i++)
		{
			cin>>a[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j)
				{
					continue;
				}
				maxn = max(maxn,a[i] & a[j]);
			}
		}
		cout<<maxn;
	}else if(m == n)
	{
		cin>>a[1];
		long long k = a[1];
		for(int i = 2;i <= n;i++)
		{
			k &= a[i];
		}
		cout<<k;
	}else{
		long long maxn = -1;
		for(int i = 1;i <= n;i++)
		{
			long long x;
			cin>>x;
			maxn = max(maxn,x);
		}
		cout<<maxn;
	}
	return 0;
}
