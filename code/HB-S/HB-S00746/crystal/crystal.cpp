#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=5e5+10;

int n,m;
int a[MAXN];
int ans;
int dp[MAXN];
unordered_map<int,int> cnt;

inline bool cmp(int A,int B)
{
	return A>B;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i],cnt[a[i]]++;
	stable_sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		if((a[1]-a[i])<=m)
		{
			++dp[1];
			m-=a[1]-a[i];
		}
		else break;
	}
	// cout<<m<<'\n';
	ans=dp[1];
	for(int i=2;i<=n;++i)
	{
		if(a[i]==a[i-1])
		{
			dp[i]=dp[i-1];
		}
		else
		{
			dp[i]=dp[i-1]-cnt[a[i-1]];
			m+=dp[i]*(a[i-1]-a[i]);
			// cout<<m<<'\n';
			for(int j=i+dp[i];j<=n;++j)
			{
				if((a[i]-a[j])<=m)
				{
					++dp[i];
					m-=a[i]-a[j];
				}
				else break;
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}