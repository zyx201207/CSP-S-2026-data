#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,a[500005],s[500005],sum,cha,cnt,maxn=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		s[i]=a[i]-a[i-1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]==a[i+1] && i+1<=n) continue;
		sum=0,cha=0,cnt=1;
		for (int j=i;j>=2;j--)
		{
			sum+=s[j];
			cha+=sum;
			if (m<cha)
			{
				break;
			}
			cnt++;
		}
		if (cnt>maxn) maxn=cnt;
	}
	printf("%lld",maxn);
	return 0;
}
