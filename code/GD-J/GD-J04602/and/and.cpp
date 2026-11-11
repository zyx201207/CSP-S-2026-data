#include <bits/stdc++.h>
using namespace std;
int n,m;
int v[200020],dp[200020],cnt[200020];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(dp,0xff,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	sort(v+1,v+n+1);
	reverse(v+1,v+n+1);
	for(int i=1;i<=n;i++)
	{
		int t=v[i];
		while(t>0)
		{
			if(t&1)
			{
				cnt[i]++;
			}
			t>>=1;
		}
	}
	int maxa=0;
	for(int i=32;i>=0;i--)
	{
		int ans=INT_MAX;
		int count=0;
		for(int j=1;j<=n;j++)
		{
			if(cnt[j]>=i and count<m)
			{
				ans&=v[j];
				count++;
				//cout<<"i:"<<i<<' '<<v[j]<<endl;
			}
		}
		if(count==m)
		{
			maxa=max(maxa,ans);
		}
	}
	cout<<maxa;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=m;j>=1;j--)
//		{
//			dp[j]=max(dp[j],dp[j-1]&v[i]);
//		}
//	}
//	cout<<dp[m];
	return 0;
} 
