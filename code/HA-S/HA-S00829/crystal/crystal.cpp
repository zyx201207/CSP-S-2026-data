#include <bits/stdc++.h>
using namespace std;
long long a[50005],dp[50005],s[50005],vis[50005],ans;
long long m;
bool check(int x,int mid)
{
	return dp[x]-mid*a[x]+s[mid]<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) dp[i]=(i-1)*a[i]-s[i-1],vis[i]=i;
	for(int i=1;i<=n;i++)
	{
		long long num=vis[i];
		if(dp[i]>m)
		{
			long long l=1,r=i;
			while(l<r)
			{
			long long mid=(l+r)/2;
				if(check(i,mid)) r=mid;
				else l=mid+1;
			}
			vis[i]-=r;
		}
		ans=max(ans,vis[i]);
	}
	
	cout<<ans;
	return 0;
} 
