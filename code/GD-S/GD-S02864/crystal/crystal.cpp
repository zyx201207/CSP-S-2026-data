#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,zd=1;
	long long s=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	for(int p=1,q=2;q<=n;)
	{
		s=a[q]*(q-p+1)-(sum[q]-sum[p-1]);
		if(s<=m&&zd<q-p+1)
		{
			zd=q-p+1;
			q++;
		}
		else if(s>m)
		p++;
		else
		q++;
		s=0;
	}
	printf("%d",zd);
	return 0;
 } 
