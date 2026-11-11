#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace did
{
	const int N=505,M=5e5+5;
	struct node {int v,val;};
	struct edge {int val,id;};
	bool operator < (const edge& x,const edge& y) {return x.val<y.val;}
	bool operator > (const edge& x,const edge& y) {return x.val>y.val;}
	int c,n,m,dd,q,T;
	int w[M];
	int d[1005][1005],d2[M],cnt[M];
	int k[N],a[M],t[M];
	vector<node> g[M];
	bool flag[M];
	void D(int bx)
	{
		priority_queue<edge,vector<edge>,greater<edge> > pq;
		for(int i=1;i<=m;i++) d[bx][i]=1e9;
		d[bx][bx]=0;
		edge xx;
		xx.val=0; xx.id=bx;
		pq.push(xx);
		memset(flag,0,sizeof(flag));
		while(!pq.empty())
		{
			edge u=pq.top();
			pq.pop();
			if(flag[u.id]) continue;
			flag[u.id]=1;
			for(int i=0;i<(int)g[u.id].size();i++)
			{
				int v=g[u.id][i].v,val=g[u.id][i].val;
				if(flag[v]) continue;
				if(d[bx][u.id]+val<d[bx][v])
				{
					d[bx][v]=d[bx][u.id]+val;
					edge yy;
					yy.val=d[bx][v]; yy.id=v;
					pq.push(yy);
				}
			}
		}
	}
	void D2(int bx)
	{
		priority_queue<edge,vector<edge>,greater<edge> > pq;
		for(int i=1;i<=m;i++) d2[i]=1e9;
		d2[bx]=0;
		edge xx;
		xx.val=0; xx.id=bx;
		pq.push(xx);
		memset(flag,0,sizeof(flag));
		while(!pq.empty())
		{
			edge u=pq.top();
			pq.pop();
			if(flag[u.id]) continue;
			flag[u.id]=1;
			for(int i=0;i<(int)g[u.id].size();i++)
			{
				int v=g[u.id][i].v,val=g[u.id][i].val;
				if(flag[v]) continue;
				if(d2[u.id]+val<d2[v])
				{
					d2[v]=d2[u.id]+val;
					edge yy;
					yy.val=d2[v]; yy.id=v;
					pq.push(yy);
				}
			}
		}
	}
	signed main()
	{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cin>>c>>n>>m>>dd>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			memset(a,0,sizeof(a));
			memset(t,0,sizeof(t));
			for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
			T=t[1];
			for(int u=1;u<=k[i];u++)
			{
				for(int v=1;v<=k[i];v++)
				{
					if(u==v) continue;
					node c1,c2;
					c1.v=a[v]; c1.val=t[u]+t[v];
					g[a[u]].push_back(c1);
					c2.v=a[u]; c2.val=t[u]+t[v];
					g[a[v]].push_back(c2);
				}
			}
		}
		if(c>=0 && c<=8 || (c>=12))
		{
			for(int i=1;i<=m;i++) D(i);
			while(q--)
			{
				int x,y;
				cin>>x>>y;
				cout<<d[x][y]+w[x]+w[y]<<"\n";
			}
		}
		if(c>=9 && c<=11)
		{
			while(q--)
			{
				int x,y;
				cin>>x>>y;
				D2(x);
				cout<<d2[y]+w[x]+w[y]<<"\n";
			}
		}
		return 0;
	}
}
signed main()
{
	did::main();
	return 0;
}
