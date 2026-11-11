#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],s[N],n,m;
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(a[i]*x-(s[i]-s[i-x])<=m)
			return 1;
	} 
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
