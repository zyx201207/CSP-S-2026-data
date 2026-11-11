#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
bool check(int x)
{
	int sum=0;
	for(int i=1;i<x;i++) sum+=a[x]-a[i];
	if(sum<=m) return true;
	for(int i=x+1;i<=n;i++)
	{
		sum-=a[i]-a[i-x+1];
		sum+=(x-1)*(a[i]-a[i-1]);
		if(sum<=m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
