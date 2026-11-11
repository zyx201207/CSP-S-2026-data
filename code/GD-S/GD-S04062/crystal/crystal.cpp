#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i,ss=1e13;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(s[i]-s[mid]-(mid-1)*(a[i]-a[mid])>m) l=mid+1;
			else r=mid-1,ss=mid;
		}
		ans=max(ans,i-ss+1);
	}
	cout<<ans;
}
