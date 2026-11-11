#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int c,n,m,d,q;
int w[N];
int k[N];
int a[550][550];
int t[550][550];
int vis[550];
int head[N<<1],tot;

int tx(int s,int e)
{
	int ans=0;
	if(vis[s]==vis[e])
	{
		ans=w[s]+a[vis[s]][s]+a[vis[e]][e];
		return ans;
	}
	return 2*w[s]+a[vis[s]][s]+2*a[vis[e]][e];
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			vis[j]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int s,e;
		scanf("%lld%lld",&s,&e);
		int dis=tx(s,e);
		printf("%lld\n",dis);
	}
}
