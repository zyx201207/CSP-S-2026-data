#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,C,T,a[N],nxt[N];
struct n1
{
	int mn,nm;
	n1 operator + (const n1 x) const
	{
		if(mn==x.mn) return {mn,nm+x.nm};
		if(mn<x.mn) return *this;
		return x;
	}
}dp[5005][5005];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n==1)
	{
		cout<<0;
	}
	else if(C==11||C==12)
	{
		int nm=d/(a[2]-a[1]);
		if(nm==1||n<nm+nm-1||nm==0)
		{
			cout<<0;
		}
		else
		{
			cout<<n-nm*2+1;
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=i;++j)
			{
				dp[j][i]={(int)1e9,0};
			}
		}
		for(int i=1;i<=n;++i)
		{
			// for(int j=i;j<=n;++j)
			// {
			// 	if(a[j]-a[i]<=d)
			// 	{
			// 		nxt[i]=j;
			// 		dp[i][nxt[i]]={1,1};
			// 	}
			// 	else break;
			// }
			// cout<<nxt[i]<<' ';
			dp[i][i]={0,1};
			for(int j=1;j<=i;++j)
			{
				for(int k=i;k>=j;--k)
				{
					if(a[i]-a[k]>d) break;
					// if(j==1&&i==4) cout<<k<<' ';
					dp[j][i]=dp[j][i]+(n1){dp[j][k].mn+1,dp[j][k].nm};
				}
				if(dp[j][i].nm>3) dp[j][i].nm=3;
			}
			// cout<<dp[1][2].mn<<' ';
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=i;++j)
			{
				if(dp[j][i].nm==2)
				{
					ans++;
				}
			}
		}
		cout<<ans;
	}
	// else if()
	cout<<'\n';
	// for(int i=1;i<=n;++i)
	// {
	// 	for(int j=1;j<i;++j)
	// }
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(cin>>C>>T;T;--T) solve();
	return 0;
}