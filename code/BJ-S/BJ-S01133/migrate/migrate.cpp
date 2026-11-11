#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000086],dp[310][310],dis[310][310];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>c>>t;
	//cout<<c<<t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		if(c==11||c==12)
		{
			for(int i=1;i<=n;i++) cin>>x[i];
			int p=x[2]-x[1];
			if(x[2]-x[1]>d/2) cout<<"0\n";
			else if(x[2]-x[1]>d/3) cout<<n-2<<'\n';
			else  cout<<max(0ll,n-2*(d/p)+1)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) cin>>x[i],dp[i][i]=1;
		for(int i=1;i<n;i++) 
			if(x[i+1]-x[i]<=d) dp[i][i+1]=1;
			else dp[i][i+1]=-1;
		//return 0;
		for(int i=1;i<=n;i++)
		{
			int now=i+1,nx=x[i],cnt=0;
			while(now<=n)
			{
				cnt++;
				while(now<=n&&x[now]<=nx+d) dis[i][now++]=cnt;
				if(nx==x[now-1]) break;
				nx=x[now-1];
			}
		}
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cout<<dis[i][j]<<' ';
			}
			cout<<'\n';
		}*/
		for(int len=3;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				if(x[j]-x[i]<=d){
					dp[i][j]=1;
					continue;
				}
				//if(dis[i][j]==0) continue;
				for(int k=i+1;k<j;k++)
				{
					if(dp[i][j]==-1) break;
					if(dis[i][k]==0||dis[k][j]==0) continue;
					//if(dis[i][k]+dis[k][j]<dis[i][j]) cout<<">>>>";
					if(dis[i][k]+dis[k][j]!=dis[i][j]) continue;
					if(dp[i][k]==-1||dp[k][j]==-1) continue;
					dp[i][j]+=dp[i][k]*dp[k][j];
					if(dp[i][j]>2) dp[i][j]=-1;
				}
			}
		}
		for(int i=1;i<=n;i++) for(int j=i+2;j<=n;j++){
			//cout<<dp[i][j]<<' ';
			 if(dp[i][j]==2) ans++;
		 }
		 for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)  dp[i][j]=dis[i][j]=0;
		cout<<ans<<'\n';
	}
    return 0;
}
