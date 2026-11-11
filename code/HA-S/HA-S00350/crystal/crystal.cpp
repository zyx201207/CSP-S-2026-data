#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int a[500005];
int s[500005];
int n,m,ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int y=1;y<=n;y++)
	{
		int l=1,r=y;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if((y-mid+1)*a[y]-s[y]+s[mid-1]<=m)
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,y-l+1);
	}
	cout<<ans;
	return 0;
}
