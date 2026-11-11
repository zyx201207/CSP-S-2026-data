#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[666666];
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--)
	{
		long long sum=m;
		long long j=1;
		while((i-j)>0)
		{
	        if(sum<=0)
	        {
				break;
			}
			j++;
	        sum-=(a[i]-a[i-j]);
		}
		ans=max(ans,j);
	}
	cout<<ans;
}