#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=500010,KKND=510;//kan kan ni de
ll c,n,m,d,q,w[M];
struct L{
	ll k;
	vector<ll> a,t;
	L()
	{
		a.push_back(0);
		t.push_back(0);
	}
}l[KKND];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++)
		scanf("%lld",w+i);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&l[i].k);
		for(ll j=1,aa,tt;j<=l[i].k;j++)
		{
			scanf("%lld%lld",&aa,&tt);
			l[i].a.push_back(aa);
			l[i].t.push_back(tt);
		}
	}
	for(ll i=1,x,y;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",max(x,y)-min(x,y));
	} 
	return 0;
}

