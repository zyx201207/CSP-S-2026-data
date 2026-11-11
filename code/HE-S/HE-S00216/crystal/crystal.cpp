#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num,dp[500005],ans,nans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		nans=0;
		num=m;
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]<=num)
			{
				nans++;
				num-=a[i]-a[j];
			}
			else
			{
				break;
			}
		}
		ans=max(ans,nans);
	}
	cout<<ans;
	return 0;
}
