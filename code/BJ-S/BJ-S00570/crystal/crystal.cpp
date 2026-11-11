#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N],sum[N];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		long long need=x*a[i],now=sum[i]-sum[i-x];
		if(need-now<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
