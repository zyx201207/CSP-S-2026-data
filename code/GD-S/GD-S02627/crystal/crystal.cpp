#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],sum[500001],maxx=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=2;i<=n;i++)sum[i]=a[i]-a[i-1]+sum[i-1];
	for(long long i=2;i<=n;i++)
	{
		for(long long j=1;j<=i;j++)
		{
			if((sum[i]-sum[j-1])<=m)
			{
				maxx=max(maxx,i-j+1);
			}
		}
	}
	cout<<maxx;
	return 0;
}
