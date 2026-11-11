#include<bits/stdc++.h>
using namespace std;
long long a[5000005],sum[5000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=0;
	for(long long i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			sum[i]=sum[i-1];
		}
		else// if(a[i]!=a[i-1])
		{
			sum[i]=(i-1)*(a[i]-a[i-1])+sum[i-1];
		}
		//cout<<a[i]<<" ";
	}
	for(long long i=1;i<=n;i++)
	{
		if(sum[i]>m)
		{
			cout<<i-1;
			return 0;
		}
	}
	
	return 0;
}
