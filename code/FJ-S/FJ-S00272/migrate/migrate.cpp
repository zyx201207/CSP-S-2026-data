#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=3e6;int C;
int n;ll d;
int pre[N];
ll x[N],f[N],sf[N],dis[N],top[N];

void Main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		pre[i]=std::lower_bound(x+1,x+i+1,x[i]-d)-x;
		// fprintf(stderr,"%d->%d\n",i,pre[i]);
	}
	ll ans=0;
	for(int u=1;u<=n;u++)
	{
		std::fill(f+1,f+n+1,0);
		std::fill(sf+1,sf+n+1,0);
		std::fill(dis+1,dis+n+1,1e9);
		std::fill(top+1,top+n+1,0);
		f[u]=1,sf[u]=1,dis[u]=0;
		// fprintf(stderr,"%d:\n",u);
		// fprintf(stdout,"\n%d: ",u);
		for(int v=u+1;v<=n;v++)
		{
			if(pre[v]<u)dis[v]=1;
			else dis[v]=dis[pre[v]]+1;
			if(dis[v]!=dis[v-1])top[v]=v;
			else top[v]=top[v-1];
			if(dis[v]>=1e9)break;
			// fprintf(stderr,"d%d=%lld %lld\n",v,dis[v],top[v]);
		}
		for(int v=u+1;v<=n;v++)
		{
			if(dis[v]>=1e9)break;
			if(dis[v]==1)f[v]=1;
			else f[v]=sf[top[v]-1]-sf[pre[v]-1];
			sf[v]=sf[v-1]+f[v];
			// fprintf(stderr,"f%d=%lld\n",v,f[v]);
			if(f[v]==2)ans++;
			// if(f[v]==2)fprintf(stdout,"%d ",v);
		}
		// fprintf(stderr,"\n");
	}
	printf("%lld\n",ans);
	// fprintf(stderr,"========================\n");
}

int main()
{
	fr(migrate)
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>C>>T;
	while(T--)Main();
	return 0;
}
