#include<cstdio>
#include<algorithm>
#include<iostream> 
#define ll long long int 
using namespace std;
const int N=5e5;
ll a[N+5],sm[N+5];
int n;
ll m;
int chck(int x,int y)
{
	return ((ll)(y-x)*a[y]-(sm[y-1]-sm[x-1]))<=m;
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
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sm[i]=sm[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(chck(mid,i))
			{
				ans=max(ans,i-mid+1),r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
