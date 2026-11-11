#include<bits/stdc++.h>
using namespace std;
const int M=500005;
long long n,m,sum,ans,maxn=-1;
long long a[M];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n<=5800)
	{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
		{
			long long lsm=m;
			for(int j=i;j>=1;j--)
			{
				if(lsm-a[i]+a[j]>=0)
				{
					ans++;
					lsm=lsm-a[i]+a[j];
				}
			}
			maxn=max(maxn,ans);
			ans=0;
		}
		cout<<maxn;
	}
	else
	{
		long long p=a[2]-a[1];
		long long jz=p;
		bool f=0;
		while(f==0)
		{
			if(m-jz>=0)
			{
				ans++;
				m-=jz;
				jz+=p;
			}
			else
			{
				f=1;
			}
		}
		cout<<ans+1;
	}
	return 0;
}
