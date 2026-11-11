#include <bits/stdc++.h>
using namespace std;

const long long MAXN=2e5+10;
struct num
{
	long long a,one;
}c[MAXN];

bool cmpx(num x,num y)
{
	if(x.one!=y.one)
		return x.one>y.one;
	return x.a>y.a;
}

bool cmpy(num x,num y)
{
	if(x.a!=y.a)
		return x.a>y.a;
	return x.one>y.one;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&c[i].a);
		long long tmp=c[i].a,cnt=0;
		while(tmp)
		{
			if(tmp&1)
				cnt++;
			tmp/=2;
		}
		c[i].one=cnt;
	}
	sort(c+1,c+n+1,cmpx);
	long long ansx=c[1].a;
	for(long long i=2;i<=m;i++)
		ansx&=c[i].a;

	sort(c+1,c+n+1,cmpy);
	long long ansy=c[1].a;
	for(long long i=2;i<=m;i++)
		ansy&=c[i].a;
	printf("%lld\n",max(ansx,ansy));
	return 0;
}