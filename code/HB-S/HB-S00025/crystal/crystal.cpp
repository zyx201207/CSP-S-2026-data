#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
int n;
int cnt,ant,bnt;
LL m,a[N],sum[N];
bool check(int x)
{
	for(int i=1;i+x-1<=n;i++)
	{
		int j=i+x-1;
		if((a[j]*x-(sum[j]-sum[i-1]))<=m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
