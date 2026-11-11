#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int c,n,m,D,T,id,a[500005],b[500005];
ll dis[1005][1005],d[500005],w[500005];
bool vis[500005];
struct node
{
	int to,w;
};
vector<node> v[1000005];
priority_queue<P,vector<P>,greater<P> > q;
inline void dij(int s)
{
	for(int i=1;i<=id;++i)
	{
		vis[i]=0;
		dis[s][i]=100000000000000000ll;
	}
	dis[s][s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto t:v[x])
		{
			if(dis[s][t.to]>dis[s][x]+t.w)
			{
				dis[s][t.to]=dis[s][x]+t.w;
				if(!vis[t.to]) q.push(make_pair(dis[s][t.to],t.to));
			}
		}
	}
	return;
}
inline void dij2(int s)
{
	for(int i=1;i<=id;++i)
	{
		vis[i]=0;
		d[i]=100000000000000000ll;
	}
	d[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto t:v[x])
		{
			if(d[t.to]>d[x]+t.w)
			{
				d[t.to]=d[x]+t.w;
				if(!vis[t.to]) q.push(make_pair(d[t.to],t.to));
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&m,&n,&D,&T);
	id=n;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&w[i]);
	}
	if(c==20||c==21)
	{
		int l1,l2;
		scanf("%d",&l1);
		for(int i=1,t;i<=l1;++i)
		{
			scanf("%d",&t);
			scanf("%d",&a[t]);
		}
		scanf("%d",&l2);
		for(int j=1,t;j<=l2;++j)
		{
			scanf("%d",&t);
			scanf("%d",&b[t]);
		}
		int minn=2e9;
		for(int i=1;i<=n;++i)
		{
			if(a[i]&&b[i]) minn=min(minn,a[i]+b[i]);
		}
		int x,y;
		while(T--)
		{
			ll ans=100000000000000000ll;
			scanf("%d %d",&x,&y);
			if(a[x]&&a[y]) ans=min(ans,1ll*a[x]+a[y]);
			if(b[x]&&b[y]) ans=min(ans,1ll*b[x]+b[y]);
			if(a[x]&&b[y]) ans=min(ans,1ll*a[x]+b[y]+minn);
			if(b[x]&&a[y]) ans=min(ans,1ll*b[x]+a[y]+minn);
			printf("%lld\n",ans+w[x]+w[y]);
		}
		return 0;
	}
	for(int i=1,tmp,x,y,preid;i<=m;++i)
	{
		scanf("%d",&tmp);
		for(int j=1;j<=tmp;++j)
		{
			scanf("%d %d",&x,&y);
			++id;
			v[x].push_back((node){id,y});
			v[id].push_back((node){x,y});
			if(j==1) continue;
			v[id].push_back((node){id-1,0});
			v[id-1].push_back((node){id,0});
		}
	}
	if(12<=c&&c<=15)
	{
		int x,y;
		while(T--)
		{
			scanf("%d %d",&x,&y);
			dij2(x);
			printf("%lld\n",d[y]+w[x]+w[y]);
		}
		return 0;
	}
	for(int i=1;i<=n;++i) dij(i);
	int x,y;
	while(T--)
	{
		scanf("%d %d",&x,&y);
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
2 5
1 5

20 2 4 20 5
1 1 1 1
3 1 1 2 2 3 100
3 2 4 3 3 4 9
1 4
*/
