#include<bits/stdc++.h>
using namespace std;
long long a[1000006];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n)
	{
		long long sum=a[1];
		sort(a+1,a+n+1);
		for(long long i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else
	{
		sort(a+1,a+n+1);
		long long sum=a[n];
		for(int i=n;i>=n-m+1;i--)
		{
			sum=sum&a[i];
		}
		cout<<sum;
	}
	return 0;
}
