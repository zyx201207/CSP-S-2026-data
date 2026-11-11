#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,a[N],sum[N],ans,cnt;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=n-2;i++)
		{
			for(long long j=i+2;j<=n;j++)
			{
				for(long long k=i+1;k<j;k++)
				{
					if(a[j]-a[k]<=d&&a[k]-a[i]<=d)
					{
						cnt++;
					}
				}
				if(cnt==2)
				{
					ans++;
				}
				cnt=0;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
