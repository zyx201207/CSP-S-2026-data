#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)? EOF:*p1++)
void read(long long &x)
{
	x=0;
	char c=gc();
	long long f=1;
	while(c>'9'||c<'0') f=(c=='-'? -f:f),c=gc();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
	x*=f;
}
long long n,m,ans;
long long a[510000];
long long sum[510000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		long long l=0,r=i+1;
		while(l+1<r)
		{
			long long mid=l+r>>1;
			long long k=sum[i]-sum[i-mid];
			if(mid*a[i]-k<=m) l=mid;
			else r=mid;
		}
		ans=max(ans,l);
	}
	printf("%lld",ans);
	return 0;
}
