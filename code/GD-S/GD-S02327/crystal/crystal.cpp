#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],s[500005];
bool check(int len)
{
	for(int l=1;l<=n-len+1;l++)
	{
		int r=l+len-1;
		if(a[r]*len-s[r]+s[l-1]<=m) return true;
	}
	return false;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
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
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
