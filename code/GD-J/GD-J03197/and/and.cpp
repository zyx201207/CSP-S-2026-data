#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans=0,flag[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=30;i>=0;i--)
	{
		ll cnt=0;
		for(int j=1;j<=n;j++)
		{
			if((a[j]&(1<<i))&&(a[j]&ans)==ans) cnt++;
		}
		if(cnt>=m) ans=ans|(1<<i);
	}
	printf("%lld",ans);
	return 0;
}
