#include<bits/stdc++.h>
using namespace std;
int ans,MAX;
int n,m;
int a[200005];
int dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		{
		cin>>a[i];
		MAX=max(a[i],MAX);
		}
	if(m==n)
	{
		int h=a[1];
		for(int i=2;i<=n;i++)
			h=h&a[i];
		cout<<h;
		return 0;
	}
	else if(m==1)
	{
		cout<<MAX;
		return 0;
	}
	else if(m==2)
	{
		MAX=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					MAX=max(MAX,a[i]&a[j]);
		cout<<MAX;
	}
	else
	{
		dp[1]=MAX;
		for(int i=1;i<=n;i++)
			for(int j=i;j>=2;j--)
				dp[j]=max(dp[j-1]&a[i],dp[j]);
		cout<<dp[m];
	}
	return 0;
}
