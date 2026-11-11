#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int ans=0;
	LL sum=0;
	for(int i=1,j=1;i<=n;i++)
	{
		sum-=a[i];
		while(sum+a[i]*(i-j+1)>m) sum+=a[j],j++;
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
