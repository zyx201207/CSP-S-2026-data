#include<bits/stdc++.h>
using namespace std;
int n,c[500005],maxn=1;
long long a[500005],m,b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	c[1]=1;
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i;
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(b[i]-b[mid-1]-(mid-1)*(a[i]-a[mid-1])>m)l=mid+1;
			else r=mid;
		}
		c[i]=i-l+1;
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	return 0;
}
