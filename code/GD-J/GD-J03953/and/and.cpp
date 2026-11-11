#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		long long sum=a[0];
		for(int i=1;i<n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
	} 
	else if(m==1)
	{
		sort(a,a+n);
		cout<<a[n-1]; 
	}
	else if(m==2)
	{
		long long maxl=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				maxl=max(maxl,a[i]&a[j]);
			}
		}
		cout<<maxl;
	}
	else if(m==n-1)
	{
		long long maxl=0;
		for(int i=0;i<n;i++)
		{
			long long sum;
			if(i==0)
			{
				sum=a[1];
			}
			else
			{
				sum=a[0];
			}
			for(int j=0;j<n;j++)
			{
				if(j==i)
				{
					continue;
				}
				sum=sum&a[j];
			}
			maxl=max(maxl,sum);
		}
		cout<<maxl;
	}
	return 0;
}
