#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	int t = 3&1;
//	cout<<t;
	int n,m;
	cin>>n>>m;
	int a[200010],dp[200010];
	int maxn = 0,maxi=0;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
			maxi = i;
		}
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	else if(m==n)
	{
		int ans = a[1];
		for(int i = 2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		int ans = 0;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(j==i) continue;
				ans = max(ans,a[i]&a[j]); 
			} 
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1)
	{
		int ans = 0;
		for(int i = 1;i<=n;i++)
		{
			int ansl = 0;
			if(i!=1) ansl = a[1];
			else ansl = a[2];
			for(int j = 1;j<=n;j++)
			{
				if(i==j) continue;
				if(i==1&&j==2) continue;
				ansl&=a[j];
			}
			ans = max(ans,ansl);
		}
		cout<<ans;
	}
	else{
		
		memset(dp,0,sizeof(dp));
		dp[1] = maxn;
		for(int i = 2;i<=m;i++)
		{
			for(int j = n;j>=1;j--)
			{
				if(j==maxi) j--;
				//cout<<(dp[i-1]&a[j])<<endl;
				dp[i] = max(dp[i],dp[i-1]&a[j]);
			}
		}
		for(int i = 1;i<=n;i++) cout<<dp[i]<<endl;
		cout<<dp[m];
	}	                                                                                                                                                                                 
	return 0;
} 
//5 3
//31 3 1 15 7
