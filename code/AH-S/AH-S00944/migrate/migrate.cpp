#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,m,ans,a[200005],dp[200005],y,x;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		x=a[2]-a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]==x)
			{
				y++;
			}
		}
		for(ll k=1;k<=n;k++)
		{
			for(int i=k+1;i<=n;i++)
			{
				y=lower_bound(a+1,a+n+1,a[i]-m)-a;
				y=max(k,y);
				dp[i]=dp[y]+1;
				x=0;
				for(int j=y;j<i;j++)
				{
					if(dp[i]==dp[j]+1)
					{
						x++;
					}
				}
				if(x==2)
				{
					ans++;
				}
			}
			for(int i=1;i<=n;i++)
			{
				dp[i]=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
