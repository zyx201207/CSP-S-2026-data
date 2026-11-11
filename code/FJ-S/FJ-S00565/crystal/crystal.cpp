#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m;
int a[N],qzh[N];
int ans=0;
bool ok(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		if(a[i]*mid-(qzh[i]-qzh[i-mid])<=m)
		return 1;
	}
	return 0;
}
void two_bound(int l,int r)
{
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(ok(mid))
		l=mid+1,ans=mid;
		else
		r=mid-1;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+a[i];
	}
	two_bound(1,n);
	cout<<ans<<endl;
	return 0;
}
//ÎÒÀ×Í­ÄàÍè 
