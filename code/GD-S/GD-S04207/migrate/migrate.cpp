#include<bits/stdc++.h>
using namespace std;
int c,t,n,l,y[2000005],ll[2000005]={0};
long long a[2000005],b[2000005],s,x[2000005],d,le[2000005];
int jj(int kk,int yy)
{
	if(ll[kk]==yy)return le[kk];
	le[kk]=0;
	ll[kk]=yy;
	if(y[kk]!=yy)return 0;
	return le[kk]=1+jj(x[kk],yy);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int ii=1;ii<=t;ii++)
	{
		l=1;
		s=0;
		scanf("%d%lld%lld",&n,&d,&a[1]);
		b[1]=0;
		for(int i=2;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			b[i]=b[i-1]+a[i]-a[i-1];
			while(l<i&&b[i]-b[l]>d)
			{
				l++;
			}
			x[l]=i;
			y[l]=ii;
		}
		for(int i=1;x[i]<n;i++)
		{
			s=s+n-x[i]-jj(x[i],ii);
		}
		printf("%lld\n",s);
	}
	return 0;
}
