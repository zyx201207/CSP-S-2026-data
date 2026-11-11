#include<bits/stdc++.h>
using namespace std;
int n,m,mp1[200005],mp[200005],now,dp[200005],ans,num,cnt,step[200005];
vector<int> wei[35],wei2[35];
bool cmp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>mp[i];
	sort(mp+1,mp+1+n);
	dp[1]=mp[1];
	step[1]=1;
	now=n;
	for (int i=2;i<=now;i++)
	{
		for (int j=1;j<i;j++)
		{
			if (step[j]!=m)
			{
				if (dp[i]<mp[i]&dp[j]){
					step[i]=step[j]+1;
					dp[i]=mp[i]&dp[j];
					if (step[i]==m) ans=max(ans,dp[i]);
				}
			}
		}
		for (int j=1;j<i;j++)
		{
			if (mp[i]&mp[j]>dp[i] && 2<=m)
			{
				dp[i]=mp[i]&mp[j];
				step[i]=2;
				if (step[i]==m) ans=max(ans,dp[i]);
			}
		}
		if (step[i]==m)
			ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
