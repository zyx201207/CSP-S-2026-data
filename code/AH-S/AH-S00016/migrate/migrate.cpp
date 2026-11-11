#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>m;
		long long a[200005];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		

		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int cnt=0;
				for(int k=i+1;k<=j-1;k++)
				{
					if((a[j]-a[k])>m||(a[k]-a[i])>m)
					{
						continue;
					}
					else if((a[j]-a[k])+(a[k]-a[i])==a[j]-a[i])
					{
						cnt++;
					}
				}
				if(cnt==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
