#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],sum[N];
bool check(int l)
{
	for(int i=l;i<=n;i++)
	{
		long long total=a[i]*l,res=total-(sum[i]-sum[i-l]);
		if(res<=m) return true ;
	}
	return false ;
}
void solve()
{
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,[](long long a,long long b){return a<b;});
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d",ans);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
		
	return 0;
}
