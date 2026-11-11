#include<bits/stdc++.h> //我真无语了，红橙黄绿 ，比去年难一万倍 
using namespace std;
int n,m,a[500005],b[300005],l[500005],e[500005];
int dp[5001][3001]={},ans[3001]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l[i]=b[a[i]];
		e[l[i]]=i;
		b[a[i]]=i;
	}
	if(n<=500)
	{
		int cnt[201]={};
		for(int i=1;i<=n;i++)
		{
			bool f[501]={},flag[201]={};
			for(int j=i;j<=n;j++)
				if(l[j]>=j&&f[l[j]]==0)
					for(int k=l[j];k<j;k++)
						f[k]=1;
			for(int j=i;j<=n;j++)
				if(f[j]==0&&flag[a[j]]==0)
					cnt[a[j]]++,flag[a[j]]=1;
		}
		for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
	} 
	else if(n<=5000)
	{
		for(int i=n;i;i--)
		{
			for(int j=1;j<=m;j++)
			{
				if(e[j])dp[i][j]=dp[e[j]][j];
				else if(j==a[i])dp[i][j]=1;
				else dp[i][j]=dp[i+1][j];
				ans[j]+=dp[i][j];
			}
		}
		for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	}
	return 0;
}





//30min的签到题是人？ 
//maybe 5g?
//100+100+100+0=300 pts.
