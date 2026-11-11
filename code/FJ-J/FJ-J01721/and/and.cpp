#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000005];
long long dp[2000005];
bool vis[2000005];
void solve()
{
	int cnt3=0,cnt1=0,cnt0=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			cnt1++;
		}
		else if(a[i]==0)
		{
			cnt0++;
		}
		else if(a[i]==2)
		{
			cnt2++;
		}
		else
		{
			cnt3++;
		}
	}
	if(max(cnt1,cnt3)>=m)
	{
		cout<<3;
	}
	else
	{
		if(cnt2+max(cnt1,cnt3)>=m)
		{
			cout<<2;
		}
		else
		{
			cout<<0;
		}
	}
}
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long maxn=LLONG_MIN;
	long long mxi=0;
	for(int i=1;i<=n;++i)
	{	
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
			mxi=i;
		}
	}
	if(maxn<4)
	{
		solve();
		return 0;
	}
	dp[0]=0,dp[1]=maxn;
	vis[mxi]=1;
	for(int i=2;i<=m;++i)
	{
		long long o=LLONG_MIN;
		for(int j=2;j<=n;++j)
		{
			if(vis[j])
			{
				continue;
			}
			if(o<(dp[i-1]&a[j]))
			{
				o=(dp[i-1]&a[j]);
				vis[j]=1;
			}
		}
		dp[i]=o;
	}
	cout<<dp[m];
	return 0;
} 
