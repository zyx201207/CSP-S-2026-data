#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],buf[500010],g,ma;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	a[n+1]=1e18;
	for(int i=1;i<=n;i++)buf[i]=buf[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i,mid,ans=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[i]*(i-mid)-(buf[i-1]-buf[mid-1])<=m)r=mid-1,ans=(i-mid+1);
			else l=mid+1;
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
