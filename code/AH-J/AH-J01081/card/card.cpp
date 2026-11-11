#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[500010];
int dp[500010];
int n,m;
int a[500010],sc[500010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof cnt);
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]==1) 
			{
				for(int k=sc[a[j]];k<=j;k++)
				{
					cnt[a[k]]=0;
				}
			}
			cnt[a[j]]++;
			sc[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			dp[j]+=cnt[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<dp[i]<<' ';
	}
	return 0;
}
