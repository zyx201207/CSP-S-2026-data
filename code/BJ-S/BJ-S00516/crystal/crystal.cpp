#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1,a[500001],pre[500001];
bool check(int l,int r)
{
	if(a[r]*(r-l+1)-pre[r]+pre[l-1]<=m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;++i)
	{
		int l=1,r=i,cnt=1e9;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i))
			{
				r=mid-1;
				cnt=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}
/*
7 84
36 39 8 -50 61 0 -23
*/
