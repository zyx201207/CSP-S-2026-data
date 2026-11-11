#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[200005];
int dp[200005];
bool is[200005];
int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(dp[1]<a[i])
		{
			dp[1]=max(dp[1],a[i]);
			p=i;
		}		
	}
	if(m==n)
	{
		int ans=1;
		for(int i=0;i<n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		cout<<ans;
		return 0;	
	}
	if(m==n-1)
	{
		int lans=0;
		for(int i=0;i<n;i++)
		{
			int ans=1;
			for(int j=0;j<n;j++)
			{
				ans=ans&a[i];
			}
			lans=max(lans,ans);
		}
		cout<<lans;
		return 0;
	}
	is[p]=1;
	cout<<dp[1]<<' '<<p<<endl;		
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(is[j]==0&&dp[i]<(dp[i-1]&a[j]))
			{
				dp[i]=max(dp[i],dp[i-1]&a[j]);
				p=j;
			}			
		}
		is[p]=1;
		cout<<dp[i]<<' '<<p<<endl;
	}
	cout<<dp[m];
	return 0;
}
