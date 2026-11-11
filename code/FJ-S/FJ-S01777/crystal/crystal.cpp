#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long INF=1e18+1;
long long a[N];
long long s[N];
int n;long long m;
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);		
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n+1,mid;
	while(l+1<r)
	{
		mid=(l+r)/2;
		long long minn=INF;
		for(int i=mid;i<=n;i++)
		{
			int st=i-mid+1,end=i;
			long long val=1ll*mid*a[end]-(s[end]-s[st-1]);
			minn=fmin(minn,val); 
		}
		if(minn<=m)l=mid;
		else r=mid;
	}
	printf("%d",l);
	return 0;
}
