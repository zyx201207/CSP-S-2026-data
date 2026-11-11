#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[500010],dp[500010][3],ans;//[0]从几开始（含），[1]消耗能量，[2]ans 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	//for(int i=0;i<n;i++)cout<<a[i]<<endl;
	dp[0][0]=0;
	dp[0][1]=0;
	dp[0][2]=1;
	for(int i=1;i<n;i++)
	{
		dp[i][0]=dp[i-1][0];
		dp[i][1]=(a[i]-a[i-1])*dp[i-1][2]+dp[i-1][1];
		dp[i][2]=dp[i-1][2]+1;
		//cout<<i<<' '<<a[i]-a[i-1]<<' '<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
		if(dp[i][1]>m)//操作不够 
		{
			while(dp[i][1]>m&&dp[i][2]>0)
			{
				dp[i][0]++;//扔掉 
				dp[i][1]-=a[i]-a[dp[i][0]];//少能量
				dp[i][2]--;
				//cout<<"!!!"<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
			}
			continue;//一定不是最大 
		}
		ans=max(ans,dp[i][2]);
	}
	cout<<ans;
	return 0;
}
