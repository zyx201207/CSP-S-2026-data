#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=500010;
int n,m,a[M],b[M],l,r,mid;
int pd(int mid)
{
	for(int i=mid;i<=n;++i)
		if(a[i]*mid-(b[i]-b[i-mid])<=m)return 1;
	return 0; 
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	l=1,r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(pd(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
