#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;ll m;
ll a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(register int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int pos=1,ans=1;ll sum=0;
	for(register int i=2;i<=n;i++)
	{
		sum+=1ll*(i-pos)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[pos],pos++;
		ans=max(ans,i-pos+1);
	}
	printf("%d\n",ans);
	return 0;
}
