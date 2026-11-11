#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005],a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=20 && m<=20)
	{
		for(int i=1; i<=n; i++)
			cin>>a[i];
		for(int i=1; i<=n; i++)
			dp[i][0]=INT_MAX;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				dp[i][j]=max(dp[i][j],dp[i][j-1]&a[i]);
		cout<<dp[n][m];
	}
	else
	{
		int ans=INT_MAX;
		for(int i=1; i<=n; i++)
		cin>>a[i];
		sort(a+1,a+n+1);
		if(m==1)
		{
			cout<<a[n];
			return 0;
		}
		if(m==2)
		{
			ans=0;
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n && j!=i; j++)
					ans=max(a[i]&a[j],ans);
			cout<<ans;
			return 0;
		}
		else
		{
			for(int i=n; i>=n-m+1; i--)
				ans&=a[i];
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
