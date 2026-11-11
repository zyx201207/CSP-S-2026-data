#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005],sum[500005],tt=1;
int b[500005],j=1;
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
  }
  sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long ban=sum[i]+m-a[i];
		if(i==1) continue;
		tt=i-1;
		if(ban/tt>=a[i])
		{
			ans=i;
      j=a[i];
		}
	}
	cout<<ans+b[j]-1;
	return 0;
}