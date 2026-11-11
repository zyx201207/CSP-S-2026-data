#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
bool check(int k)
{
	for (int i=1;i<=n-k+1;i++)
		if(a[i+k-1]*k-s[i+k-1]+s[i-1]<=m)
			return true;
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
