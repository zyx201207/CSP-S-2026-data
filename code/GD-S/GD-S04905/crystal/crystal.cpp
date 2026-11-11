# include <cstdio>
# include <algorithm>
# define int long long
using namespace std;
int n,m,a[1000007],qz[1000007];
int pan(int x)
{
	for(int i=x;i<=n;i++)
	{
		int ans=a[i]*x-(qz[i]-qz[i-x]);
		if(ans<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	//printf("\n");
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(pan(mid)==1) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
