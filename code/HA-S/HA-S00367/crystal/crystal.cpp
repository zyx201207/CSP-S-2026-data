#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	int l=1,r=1;
	for(;r<=n;r++)
	{
		while(l<r&&sum[r]-sum[l-1]+m<a[r]*(r-l+1)) l++;
		if(l<=r) ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
