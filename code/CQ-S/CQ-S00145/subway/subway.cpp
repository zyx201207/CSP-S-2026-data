#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,s,e,gunmu,v[501];
long long w[500001],d[501],f[501][501];
struct node{long long k;int v;};
vector<node>b[500001],t[501],g[501];
void dijskra(int s)
{
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
	for(auto i:b[s]) pq.push({i.k,i.v}),d[i.v]=i.k;
	while(!pq.empty())
	{
		int u=pq.top().second;
		long long l=pq.top().first;
		//printf("%d:%lld\n",u,l);
		pq.pop();
		if(v[u]) continue;
		v[u]=1;
		//printf("%d\n",u);
		for(auto i:g[u]) if(l+i.k<d[i.v]) d[i.v]=l+i.k,pq.push({d[i.v],i.v});
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f3f3f,sizeof f);
	scanf("%d%d%d%d%d",&c,&n,&m,&gunmu,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int f;
		scanf("%d",&f);
		for(int j=1;j<=f;j++)
		{
			int x;
			long long l;
			scanf("%d%lld",&x,&l);
			b[x].push_back({l,i});
			t[i].push_back({l,x});
		}
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(auto k:t[i]) for(auto l:t[j]) if(k.v==l.v) f[i][j]=min(f[i][j],k.k+l.k);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) g[i].push_back({f[i][j],j}),g[j].push_back({f[i][j],i});
	/*for(int i=1;i<=n;i++)
	{
		for(auto j:g[i]) printf("%d %d %lld\n",i,j.v,j.k);
		printf("\n");
	}*/
	for(int i=1;i<=q;i++)
	{
		memset(d,0x3f3f3f3f,sizeof d);
		memset(v,0,sizeof v);
		scanf("%d%d",&s,&e);
		dijskra(s);
		long long ans=0x3f3f3f3f;
		for(auto j:b[e]) ans=min(ans,d[j.v]+j.k);
		//for(auto j:b[e]) printf("%d %lld\n",j.v,d[j.v]+j.k);
		printf("%lld\n",w[s]+w[e]+ans);
	}
	return 0;
}
/*
swap(±ß,µã); 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
