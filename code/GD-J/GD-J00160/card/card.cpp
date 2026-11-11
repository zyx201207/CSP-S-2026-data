#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],zh[300005],ans[300005],l;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),zh[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		l=i;
		while(l<=n)ans[a[l]]++,l=zh[a[l]]+1;
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}
