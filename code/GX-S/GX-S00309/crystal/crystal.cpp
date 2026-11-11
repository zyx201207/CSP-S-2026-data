#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;

long long n,m,a[5000001],f[5000001],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	  f[i]=f[i-1]+a[i];
	
	for(int i=1;i<=n;i++)
	{
		long long l=0,r=i-1;
		while(l<=r)
		{
		  long long mid=(l+r)/2;
		  if(a[i]*(i-1-mid)-(f[i]-f[mid-1])<=m)
		    ans=max(ans,i-mid),r=mid-1;
		  else
		    l=mid+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
