#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],d[500005],dp[500005];//d两个水晶球能量差，dp合并i号球时最多球数
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	long long y=1,x=0,ans=0,now=0;//y:已经可以合并的最后一个球号数 ，x:从第x+1号球开始合并，y-x:已经合并的球数 
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		now=now+(y-x)*d[i];
		y++;
		if(now<=m)
		{
			dp[i]=y-x;
			continue;
		}
		while(x<=y)
		{
			now-=(a[y]-a[x+1]);
			x++;
			if(now<=m)
			{
				dp[i]=y-x;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
//		cout<<dp[i]<<endl;
	}
	cout<<ans;
//	for(int i=1;i<=n;i++) cout<<p[i]<<endl;
	return 0;
}
