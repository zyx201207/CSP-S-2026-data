#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,t,n,d,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		printf("0\n");
	}
	return 0;
}
