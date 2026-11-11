#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long sum[1000001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j,t=1;
	long long ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(i>t)
		{
			t=i;
		}
		for(j=t;j<=n;j++)
		{
			if((j-i+1)*a[j]-sum[j]+sum[i-1]>m)
			{
				t=j-1;
				break;
			}
			if(j-i+1>ans)
			{
				ans=j-i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
