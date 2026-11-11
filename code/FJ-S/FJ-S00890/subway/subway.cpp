#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll k,a[500010],t[500010];
};
struct node2
{
	ll x,y;
}
ll c,n,m,d,q;
ll w[500010];
node ar[510];
node2 br[100010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&ar[i].k);
		for(int j=1;j<=ar[i].k;j++)
		{
			scanf("%lld%lld",&ar[i].a[j],&ar[i].t[j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&br[i].x,&br[i].y);
	}
	
	return 0;
}

