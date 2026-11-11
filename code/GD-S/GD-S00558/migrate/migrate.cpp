#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=1e9+7;
const ll MAXN=2e6+5;
const ll inf=LONG_LONG_MAX;
ll n,m,a[MAXN],dp[MAXN],vis[MAXN];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll l=i,cnt=1;
		dp[i]=0;
		vis[i]=1;
		for(int j=i+1;j<=n;j++)
		{
			while(l<j&&a[l]+m<a[j])
			{
				if(vis[l]<3)cnt--;
				l++;
			}
			if(l==j||!cnt)break;
			if(j-l==1||dp[l]!=dp[l+1])
			{
				if(vis[l]==2)
				{
					ans++;
				}
			}
			if(j-l>1&&dp[l]==dp[l+1]&&vis[l]==1&&vis[l+1]==1)
			{
				if(j-l==2||dp[l]!=dp[l+2])
				{
					ans++;
				}
			}
			dp[j]=dp[l]+1;
			if(j-l==1||dp[l]!=dp[l+1])vis[j]=vis[l];
			else
			if(j-l==2||dp[l]!=dp[l+2])vis[j]=min(3ll,vis[l]+vis[l+1]);
			else vis[j]=3;
			if(vis[j]<3)cnt++;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin>>T;
	cin>>T;
	while(T--)solve();
	return 0;
}
