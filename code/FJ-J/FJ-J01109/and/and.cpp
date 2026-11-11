#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],ma=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ma=max((ll)ma,(ll)a[i]);
	}
	if(m==1)
	{
		printf("%lld\n",ma);
		return 0;
	}
	return 0;
}
