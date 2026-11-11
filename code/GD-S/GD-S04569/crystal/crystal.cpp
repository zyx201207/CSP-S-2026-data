#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans;
int check(int x)
{
	int mn=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n-x+1;i++)
	{
		mn=min(mn,x*(a[i+x-1]-a[i+x-2])-a[i+x-1]+a[i-1]);
	}
	return mn;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)	a[i]=a[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)<=m)
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
