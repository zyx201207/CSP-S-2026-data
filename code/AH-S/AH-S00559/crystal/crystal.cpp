#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=5e5+3;
LL a[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	LL sum=0;
	for(int i=2,j=1;i<=n;i++)
	{
		int len=i-j;
		sum+=(a[i]-a[i-1])*len;
		while(sum>m)
		{
			sum-=a[i]-a[j];
			j++;
			len--;
		}
		ans=(len+1>ans?len+1:ans);
	}
	printf("%d",ans);
	return 0;
}
