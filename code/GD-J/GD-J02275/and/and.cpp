#include <bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[100010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		long long mx;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mx=max(mx,(a[i] & a[j]));
			}
		}
		cout<<mx;
	}
	if(m==n)
	{
		long long sum=(a[1] & a[2]);
		for(int i=3;i<=n;i++)
		{
			sum=(sum & a[i]);
		}
		cout<<sum;
	}
	if(m==1)
	{
		long long mx2;
		for(int i=1;i<=n;i++)
		{
			mx2=max(mx2,a[i]);
		}
		cout<<mx2;
	}
	return 0;
}
