#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[500005],s[500005];
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		ll ss=(mid-1)*a[i]-(s[i-1]-s[i-mid]);
		if(ss<=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
