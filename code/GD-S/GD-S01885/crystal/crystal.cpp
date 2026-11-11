#include<bits/stdc++.h>
using namespace std;
long long n,m,ma,lo;
long long numb[5000005];
map<long long,long long> to;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ma=-1;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		long long a;
		scanf("%lld",&a);
		if(!to[a]) numb[++lo]=a;
		to[a]++;
	}
	sort(numb+1,numb+1+lo);
	for(long long i=1;i<=lo;i++)
	{
		long long mm=m,tot=0;
		for(long long j=i-1;j>=1;j--)
		{
			long long di=numb[i]-numb[j],ca;
			if(mm<=0||mm<di) break;
			ca=min(mm/di,to[numb[j]]);
			tot+=ca,mm-=(di*ca);
		}
		ma=max(ma,tot+to[numb[i]]);
	}
	printf("%lld",ma);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

