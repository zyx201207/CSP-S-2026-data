#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
int n;
ll m,a[N];
ll s[N];
int mx;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(m>=i*a[i]-s[i])
		{
			mx=max(mx,i);
			continue;
		}
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			int len=i-mid+1;
			if((long long)len*a[i]-(s[i]-s[mid-1])>m)
			l=mid+1;
			else
			r=mid;
		}
		mx=max(mx,i-l+1);
	}
	printf("%d",mx);
	return 0;
} 

