#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
const ll M=3e5+10;
ll n,m,a[N],ans[M];
ll t[M];
void game(ll p)
{
	memset(t,0,sizeof(t));
	vector<ll> asn;
	for(int i=p;i<=n;i++)
	{
		if(t[a[i]]!=0)
		{
			while(asn.back()!=a[i])
			{
				asn.pop_back();
			}
			asn.pop_back();
		}
		asn.push_back(a[i]);
		t[a[i]]++;
	}
	for(int i=0;i<ll(asn.size());i++)
	{
		ans[asn[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		game(i);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}
