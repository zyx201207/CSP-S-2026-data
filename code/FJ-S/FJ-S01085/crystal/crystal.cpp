#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=5e5+10;
long long a[N];
long long n;
long long m;
long long b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	long long ret=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			long long qw=a[mid]*(mid-i+1);
			long long cnt=qw-(b[mid]-b[i-1]);
			if(cnt<=m)
			{
				ret=max(ret,(long long)(mid-i+1));
				l=mid+1;
			}
			else r=mid-1;
		}
	}
	printf("%lld\n",ret);
	return 0;
}
