//GZ-S00142 ½¯•Fê» 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long m,T,n,d,a[N],ans,dp[N],bs[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>m>>T;
	while(T--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i;j<=n;j++) dp[j]=0,bs[j]=INT_MAX;
			for(int j=i;j<=n;j++)
			{
				if((a[j]-a[i])<=d)
				{
					dp[j]=1;
					bs[j]=1;
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j-1;k>=i;k--)
				{
					if((a[j]-a[k])<=d)
					{
						if(bs[k]+1==bs[j])
						{
							dp[j]++;
						}
						else if(bs[k]+1<bs[j])
						{
							dp[j]=1;
							bs[j]=bs[k]+1;
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				
			}
			/*
			cout<<"i="<<i<<endl;*/
			//for(int j=i;j<=n;j++) cout<<bs[j]<<" ";
			//cout<<endl;
			//for(int j=i;j<=n;j++) cout<<dp[j]<<" ";
			/*
			cout<<endl;
			*/
			for(int k=i;k<=n;k++)
			{
				if(dp[k]==2)
				{
					ans++;
				}
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
10 3 
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
0 1 8 3 0 1 2 4 8 10 11 13
*/
