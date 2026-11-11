#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],s[500010];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(a[i]*x-(s[i]-s[i-x])<=m) return 0;
	}
	return 1;
}
int solve(int l,int r)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	return (l-1);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	cout<<solve(1,n);
	return 0;
}
