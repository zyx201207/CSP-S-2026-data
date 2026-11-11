#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,ans,a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
		int l=0,r=i,mid;
		while(l+1<r)
		{
			mid=l+r>>1;
			if(a[i]*(long long)(i-mid)-b[i-1]+b[mid-1]<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,(long long)(i-r+1));
	}
	printf("%lld",ans);
	return 0;
}
