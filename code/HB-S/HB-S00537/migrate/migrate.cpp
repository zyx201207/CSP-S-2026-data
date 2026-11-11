#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n,l[2000200];
ll d,a[2000200];
ll dp[2000200][2],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		}
		for(int i=1;i<=n;i++)
		{
			if(l[i]==i) continue;
			dp[i][0]=dp[l[i]][0];
			if(l[i]==1) dp[i][0]=1;
			else if(a[l[l[i]]]+d<a[l[i]+1]||l[l[i]]==l[i]) dp[i][0]++;
			if(l[i]+1<i)
			{
				if(a[l[l[i]+1]]+d<a[l[i]+2]) dp[i][1]+=dp[l[i]+1][0];
			}
			//cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
			ans+=dp[i][1];
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=0;
	}
	return 0;
}
