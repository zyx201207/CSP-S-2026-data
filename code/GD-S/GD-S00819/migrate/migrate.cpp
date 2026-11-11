#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=2e6+5;
int CC,T;
int n;
long long maxd;
long long a[N];
int cnt[305][305];
int dp[305][305];
signed main()
{
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>CC>>T;
	while(T--)
	{
		cin>>n>>maxd;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
		}
		if(n<=3)
		{
			cout<<0<<endl;
			continue;
		}
		if(flag)
		{
			long long d=a[n]-a[n-1];
			if(d>=maxd) cout<<0<<endl;
			else cout<<max(0ll,n-maxd/d*2+1)<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1e18,cnt[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>maxd) break;
				dp[i][j]=1;
				cnt[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		for(int len=3;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				if(dp[i][j]==1) continue;
				for(int k=j-1;k>=i;k--)
				{
					if(a[j]-a[k]>maxd) break;
					if(dp[i][k]+1==dp[i][j]) cnt[i][j]+=cnt[i][k];
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
////				if(dp[i][j]>=1e18) cout<<-1<<' ';
//				cout<<cnt[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(cnt[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
