#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

ll c,t;

inline ll abss(ll a)
{
	return (a<0?(-a):a);
}

int main()
{
	scanf("%lld%lld",&c,&t);
	for(t;t;--t)
	{
		ll n,d,x[2000005],ans=0;
		scanf("%lld%lld",&n,&d);
		vector<ll> dis[n+1];
		for(ll i=1;i<=n;++i)
		{
			for(ll j=0;j<=n;++j)
			{
				dis[i].push_back(0x3f3f3f3f);
			}
		}
		scanf("%lld",&x[1]);
		for(ll i=2;i<=n;++i)
		{
			scanf("%lld",&x[i]);
			for(ll j=i;j>=1;--j)
			{
				ll cca=abss(x[i]-x[j]);
				if(cca<=d)
				{
					dis[i][j]=cca;
					dis[j][i]=cca;
				}
			}
		}
		for(ll k=1;k<=n;++k)
		{
			for(ll i=1;i<=n;++i)
			{
				if(i==k) continue;
				for(ll j=1;j<=n;++j)
				{
					if(i==j||j==k) continue;
					if(dis[i][k]+dis[k][j]==dis[i][j]&&dis[i][j]!=0x3f3f3f3f)
					{
						++ans;
					}
					else if(dis[i][k]+dis[k][j]<dis[i][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
