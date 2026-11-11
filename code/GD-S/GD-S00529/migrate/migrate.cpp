#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d,dis;
ll a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&d);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		bool ok=1;
		for (int i=2;i<=n;i++) ok=ok&(a[i]-a[i-1]==a[2]-a[1]);
		if (ok)
		{
			dis=a[2]-a[1];
			if (dis>=d||dis*n<=d) printf("0\n");
			else printf("%lld\n",n-d/dis*2+1);
		}
		printf("0\n");
	}
	return 0;
}
