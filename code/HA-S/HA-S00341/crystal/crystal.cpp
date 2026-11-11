#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[600010],s[600010];
int n,m;
int usn(int k)
{
	int mx=3e18;
	for(int i=1;i<=n-k+1;i++)
	{
		int ret=a[i+k-1]*k-(s[i+k-1]-s[i-1]);
		mx=min(mx,ret);
	}
	return mx;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
	int mx=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(usn(mid)<=m)
		{
			mx=max(mx,mid);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<mx;
	return 0;
	
}

