#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ds[500005],deng,ans,sum[500005];
bool isdeng=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
		if(i==2)
			deng=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=deng)
			isdeng=0;
	}
	if(isdeng)
	{
		long long temp=1;
		while(m>0)
		{
			m-=temp*deng;
			++temp;
			++ans;
		}
		cout<<ans+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n-1;++i)
	{
		ds[i]=(a[i+1]-a[i])*(i);
		sum[i]=sum[i-1]+ds[i];
	}
	/*for(long long i=1;i<=n-1;++i)
		cout<<ds[i]<<" ";
	cout<<"\n";
	for(long long i=1;i<=n-1;++i)
		cout<<sum[i]<<" ";
	cout<<"\n";*/
	if(sum[n-1]<=m)
	{
		cout<<n;
		return 0;
	}
	/*for(long long i=1;i<=n-1;++i)
	{
		for(long long j=n-1;j>=1;--j)
		{
			if(i>j)
				break;
			if(sum[j]-sum[i-1]<=m)
				ans=max(ans,j-i+1);
		}
	}*/
	for(long long i=1;i<=n-1;++i)
	{
		for(long long j=n-1;j>=1;--j)
		{
			if(i>j)
				break;
			if(sum[j]-sum[i-1]<=m)
			{
				ans=max(ans,j-i+1);
				break;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
