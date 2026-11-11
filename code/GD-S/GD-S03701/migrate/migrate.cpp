#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace C{
	ll a[2000010];
	int main(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		int migrate,t;
		scanf("%d%d",&migrate,&t);
		while (t--)
		{
			ll n;
			ll m;
			scanf("%lld%lld",&n,&m);
			for (int i=1;i<=n;i++)
			{
				scanf("%lld",&a[i]);
			}
			ll sum=0;
			ll i=2;
			int cnt=0;
			for (;i<=n;i++)
			{
				sum+=a[i]-a[i-1];
				if (sum>m)
				{
					i-=2;
					cnt++;
					sum=0;
					if (cnt==2)break;
				}
			}
			printf("%lld\n",n-i);
		}
		return 0;
	}
};
int main(){
	return C::main();
}
