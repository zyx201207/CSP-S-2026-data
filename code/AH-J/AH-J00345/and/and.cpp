#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],n,m,dp[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int tot=0;
		for(int i=1;i<=n;i++) tot&=a[i];
		cout<<tot;
		return 0;
	}
	if(m==2)
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	dp[1]=a[n];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[j]=max((dp[j-1]&a[j]),dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}
