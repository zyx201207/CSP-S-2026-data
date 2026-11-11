#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
int p[N];
bool check(int mid)
{
	for(int i=1;i<=n-mid+1;i++)
	{
		int j=i+mid-1;
		if((mid-1)*a[j]-(p[j-1]-p[i-1])<=m) 
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		p[i]=p[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid;
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
* 
5 8
-3 -1 2 2 7
*/
