#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],s[N];
bool check(int x)
{
	for(int i=x;i<=n;++i)
	{
		if(a[i]*x-s[i]+s[i-x]<=m)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
