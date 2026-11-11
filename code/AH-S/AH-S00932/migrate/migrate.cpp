#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005],dp[305][2];
int n,m;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int xza=1,xzb=1,xzc=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>=3&&(a[i]-a[i-1])!=(a[i-1]-a[i-2]))
				xza=0;
		}
		if((c>=1&&c<=6)||n<=300)
		{
			int s=0;
			for(int i=1;i<=n;i++)
			{
				memset(dp,0x3f,sizeof(dp));
				dp[i][0]=0,dp[i][1]=1;
				for(int j=i;j<=n;j++)
				{
					int x=dp[j][0]+1;
					for(int k=j+1;a[j]+m>=a[k]&&k<=n;k++)
					{
						if(x<dp[k][0])
							dp[k][0]=x,dp[k][1]=dp[j][1];
						else if(x==dp[k][0])
							dp[k][1]+=dp[j][1];
						//cout<<k<<":"<<dp[k][0]<<" "<<dp[k][1]<<endl;
					}
				}	
				for(int j=i+1;j<=n;j++)
					s+=(dp[j][1]==2);			
			}
			cout<<s<<endl;
			continue;
		}
		if(xza||c==11||c==12)
		{		
			xza=a[2]-a[1];
			int k=m/xza;
			if(k<=1||2*k>n)
				cout<<0<<endl;
			else
				cout<<n-2*k+1<<endl;
			continue;
		}
		if(c==13||c==14)
		{
			int phd=0,phd1=0,phd2=0,s=0;
			for(int i=1;i<=n;i++)
				if(a[1]+m>=a[i]&&a[n]-m<=a[i])
				{
					phd++;
					cout<<a[i]<<" ";
					if(phd==1)
						phd1=i;
					if(!(a[1]+m>=a[i+1]&&a[n]-m<=a[i+1]))
						phd2=i;
				}
			if(phd==1)
			{
				for(int i=phd1+1;i<=n;i++)
					if(a[phd1-1]+m>=a[i]&&a[phd1-2]+m<=a[i])
						s++;
				cout<<s<<endl;
			}
			else if(phd==2)
			{
				for(int i=phd2+1;i<=n;i++)
					if(a[phd1-1]+m<=a[i])
						s++;
				cout<<s<<endl;			
			}
			else
				cout<<0<<endl;
			for(int i=1;i<=n;i++)
				a[i]=0;
			continue;
		}
	}
	return 0;
}

