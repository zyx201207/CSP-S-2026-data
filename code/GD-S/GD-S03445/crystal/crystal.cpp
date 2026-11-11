#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],t[N],n,m;
long long find(long long x)
{
	long long l=1,r=x,mid,ans=x;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(t[x]-t[mid-1])<=m)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return x-ans+1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	long long i,x,ans=0,add=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		add=min(add,a[i]);
		t[i]=t[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		x=find(i);
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}
