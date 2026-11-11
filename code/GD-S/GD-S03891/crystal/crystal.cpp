#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500050];
bool ch(int x)
{
	int he=0;
	for(int i=1;i<=x;++i) he+=a[x]-a[i];
	if(he<=m) return 1;
	for(int i=x+1;i<=n;++i)
	{
		he+=(a[i]-a[i-1])*x;
		he-=a[i-1]-a[i-x];
		if(he<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(ch(mid)) 
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
