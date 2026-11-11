#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,a[500010],d[500010];
bool v[500010];
long long siz=0,pl[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m); 
	bool sa=1;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=2;i<=n;i++)sa=sa&(a[i]>=a[i-1]);
	if (sa)
	{
		for (int i=2;i<=n;i++)if (a[i]!=a[i-1])printf("%d ",i-1);
		printf("%d",n);
		return 0;
	} 
	if (m<=2)
	{
		for (int i=1;i<=n;i++)
		{
			d[a[n]]++;
			if (d[a[i]]!=d[a[n]])d[a[i]]++;
		}
		for (int i=1;i<=m;i++)printf("%d ",d[i]);
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		siz=0;
		for (int j=1;j<=m;j++)v[j]=0;
		for (int j=i;j<=n;j++)
		{
			int k=siz+1;
			for (int s=1;s<=siz;s++)
			{
				if (pl[s]==a[j])
				{
					k=s;
					break;
				}
			}
			//cout<<k<<' ';
			if (k==siz+1)pl[++siz]=a[j];
			else pl[k]=a[j],siz=k;
			//cout<<endl;for (int j=1;j<=siz;j++)cout<<pl[j]<<' ';cout<<endl;
		}
		for (int j=1;j<=siz;j++)if (!v[pl[j]])d[pl[j]]++,v[pl[j]]=1;
		//cout<<endl;
	}
	for (int i=1;i<=m;i++)printf("%d ",d[i]);
	return 0;
}
