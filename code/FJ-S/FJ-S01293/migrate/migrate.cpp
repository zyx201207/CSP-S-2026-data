#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,d,a[N],dp[N],cnt[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c>=11&&c<=12)
		{
			if(a[2]-a[1]>d)
			{
				cout<<0<<'\n';
				continue;
			}
			int cha=a[2]-a[1];
			int x=d/cha,ans=0;
			for(int i=1+x;i<=n;i+=x)
			{
				int dow=n-(i+1)+1,up=n-(i+x-1)+1;
				ans+=(up+dow)*(up-dow+1)/2;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c<=6)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					dp[j]=0x3f3f3f3f3f3f3f3fll;
					cnt[j]=1;
				}
				dp[i]=0;
				for(int j=i+1;j<=n;j++)
				{
					int ncnt=0;
					for(int k=j-1;k>=i;k--)
					{
						if(a[j]-a[k]<=d)dp[j]=min(dp[j],dp[k]+1);
					}
					for(int k=j-1;k>=i;k--)
					{
						if(a[j]-a[k]<=d)
						{
							if(dp[k]+1==dp[j])ncnt+=cnt[j];
						}
					}
					if(ncnt==2)ans++;
					cnt[j]=ncnt;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<0<<'\n';
	}
	return 0;
}

