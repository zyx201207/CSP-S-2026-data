#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0; 
int a[500005];
//int sum[500005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=1,u=0,sum=1;
	while(r<=n)
	{
		ans=max(ans,sum);
		if(u+(a[r+1]-a[r])*(r-l+1)<=m)
		{
			u+=(a[r+1]-a[r])*(r-l+1);
			sum++;r++;
		}
		else
		{
			u-=(a[r]-a[l]);
			sum--;l++;
		}
	}cout<<ans;
	return 0;
}
