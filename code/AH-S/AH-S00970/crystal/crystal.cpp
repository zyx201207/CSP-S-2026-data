#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long x[500005];
long long ans1,l,r;
bool check(long long a,long long b,long long c,long long d,long long e)
{
	int ch=d*a;
	int sh=c-b;
	if(ch+sh<=e)
		return true;
	else
		return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,ans=0;
	scanf("%d%lld",&n,&m);
	int q=1;
	while(q<=n)
	{
		scanf("%lld",&a[q]);
		++q;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	x[i]=x[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		l=1,r=i;
		ans1=0;
		while(r>=l)
		{
			long long mid=(l+r)>>1;
			if(i-mid>=0&&check(a[i],x[i],x[i-mid],mid,m))
			{
				ans1=mid;
				l=mid+1;
			}
			
			else
			r=mid-1;
		}
		
		if(ans<ans1)
		ans=ans1;
	}
	printf("%lld",ans);
	return 0;
}
