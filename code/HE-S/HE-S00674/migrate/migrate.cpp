#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+50;
ll a[N],dp[N],cnt,ans;
inline void solve()
{
	int n;
	ans=0;
	ll d;
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		dp[i]=1e18;
	}
	int tot=1;
	while(tot<n)
	{
		dp[tot]=0;
		for(int i=tot+1;i<=n;++i)
		{
			dp[i]=1e18;
			cnt=0;
			int t=tot;
			for(int j=t;j<i;++j)
			{
				if(a[j]+d<a[i])
				{
					t++;
					continue;
				}
				if(dp[j]+1<dp[i])
				{
					dp[i]=dp[j]+1;
					cnt=0;
				}
				else if(dp[i]==dp[j]+1)
				{
					cnt++;	
				}
			}
			if(cnt)
				if(cnt==1) ans++;
		}
		tot++;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T,c;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
