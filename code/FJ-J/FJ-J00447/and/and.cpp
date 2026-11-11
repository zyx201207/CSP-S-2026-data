#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,ans=34359738367;
bool v[200010];
struct nb
{
	long long sz;
	int d[40];
	bool operator < (const nb c) const
	{
		for (int j=32;j>=0;j--)if (d[j]!=c.d[j])return d[j]>c.d[j];
		return sz>c.sz;
	}
}a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)for (int j=0;j<=35;j++)a[i].d[j]=0;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i].sz);
	for (int i=1;i<=n;i++)
	{
		long long x=a[i].sz;int j=0;
		while(x>0)a[i].d[j]=x%2,x/=2,j++;
	}
	sort(a+1,a+n+1);
	int nha=0;
	for (int j=32;j>=0;j--)
	{
		int cnt=0,nda=0,bh1=0,bh2=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i].d[j]==1)(!bh1? bh1:bh2)=i,cnt++,nda+=(v[i]==0);
			if (cnt==2)break;
		}
		if (cnt<2||nda+nha>m)continue;
		v[bh1]=v[bh2]=1,nha+=nda;
		if (nha==m)break;
	}
	for (int i=1;i<=n;i++)
	{
		if (nha==m)break;
		if (!v[i])v[i]=1,nha++;
	}
	for (int i=1;i<=n;i++)if (v[i])ans=(ans&(a[i].sz)); 
	printf("%lld",ans);
	return 0;
}
