#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2222222];
long long dp[2222222],l[2222222];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	vector<long long>ans;
	for(long long uuuuu=0;uuuuu<t;uuuuu++)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>x[i];
		long long cnt=0;
		for(long long i=1;i<=n;i++)
		{
			memset(dp,0,2222222);dp[i]=1;memset(l,1,2222222);l[i]=0;
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=i;k<j;k++)
				{
					if(x[j]-x[k]<=d)
					{
						//cout<<1;
						if(l[k]+1==l[j])dp[j]+=dp[k];
						else if(l[k]+1<l[j])
						{
							dp[j]=dp[k];
							l[j]=l[k]+1;
						}
					}
				}
				//cout<<dp[j]<<' ';
				if(dp[j]==2)cnt++;
			}
		}
		ans.push_back(cnt);
	}
	for(long long h:ans)cout<<h<<'\n';
}
