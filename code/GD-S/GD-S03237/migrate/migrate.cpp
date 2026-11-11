#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll RainbowDash=2000010;
ll C,T,n,d,x[RainbowDash];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++)
			scanf("%lld",x+i);
		if(C==11||C==12)
		{
			ll gc=x[2]-x[1];
			ll bs=d/gc,ans=0;
			for(ll i=2;i<=bs;i++)
				ans+=n-bs-1;
			printf("%lld\n",ans);
			continue;
		}
		ll sum=0;
		for(ll i=1;i<n;i++)
			for(ll j=i+1,minn,cnt;j<=n;j++)
			{
				cnt=0,minn=LLONG_MAX;
				queue<P> q;
				q.push(make_pair(i,0LL));
				while(!q.empty())
				{
					P t=q.front();
					q.pop();
					ll ta=t.first,tb=t.second;
					if(ta==j)
					{
						if(tb<minn)
							minn=tb,cnt=1;
						else if(tb==minn)
						{
							cnt++;
							if(cnt>2)
								break;
						}
						continue;
					}
					if(tb+1>minn)
						continue;
					tb++;
					for(ll k=ta+1;k<=j;k++)
					{
						if(x[k]-x[ta]>d)
							break;
						q.push(make_pair(k,tb));
					}
				}
				if(cnt==2)
					sum++;
			}
		printf("%lld\n",sum);
	}
	return 0;
}

