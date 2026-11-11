#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[500010],hx[300010],ma[500010],h=1,w[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1])
		{
			h=0;
		}
	}
	if(h)
	{
		for(int i=1;i<=n;i++)
		{
			w[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			printf("%lld ",w[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ll g=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=g;k++)
			{
				if(ma[k]==a[j])
				{
					g=k-1;
					break;
				}
			}
			ma[++g]=a[j];
		}
		for(int j=1;j<=g;j++)
		{
			hx[ma[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",hx[i]);
	}
	return 0;
}
