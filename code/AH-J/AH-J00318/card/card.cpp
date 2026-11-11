#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v,w;
ll s[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll i,n,m,x;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		v.push_back(x);
	}
	while(n--)
	{
		
	}
	for(i=1;i<=m;i++)
	{
		printf("%lld ",s[i]);
	}
	return 0;
}
