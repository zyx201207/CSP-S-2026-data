#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int n;
long long a[N],q[N],K;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&K);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		for(;l<r;)
		{
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(q[i]-q[mid-1])<=K) r=mid;
			else l=mid+1;
		}
		res=max(res,i-l+1);
	}
	printf("%d\n",res);
	return 0;
}

