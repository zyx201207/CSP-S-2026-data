#include<bits/stdc++.h>
using namespace std;
const int N=500000+500+1;//100010
const long long inf=1e18;
int c,n,m,d,q,f;
long long ans;
long long w[500001];
struct node
{
	int to,last;
	long long len;
};
node g[1000001];
struct tree
{
	int id;
	long long v;
};
tree t[N<<2];
int kt,pre[N];
void add(int x,int y,long long z)
{
	kt++;
	g[kt].to=y;
	g[kt].last=pre[x];
	g[kt].len=z;
	pre[x]=kt;
}
long long p[501][N];//最小值 
bool o[N];//是否没去过
tree cmp(tree a,tree b)
{
	return a.v<b.v?a:b;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		t[k].id=l;
		t[k].v=inf;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	t[k]=cmp(t[k<<1],t[k<<1|1]);
}
void upd(int k,int l,int r,int x,long long v)
{
	if(l==r&&l==x)
	{
		t[k].v=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	{
		upd(k<<1,l,mid,x,v);
	}
	else
	{
		upd(k<<1|1,mid+1,r,x,v);
	}
	t[k]=cmp(t[k<<1],t[k<<1|1]);
}
void dj(int x)
{
	build(1,1,f);
	for(int i=1;i<=f;i++)
	{
		o[i]=true;
		p[x][i]=inf;
	}
	p[x][x+m]=0;
	upd(1,1,f,x+m,0);
	int id;long long v;
	while(true)
	{
		id=t[1].id;
		v=t[1].v;
		if(v==inf)
		{
			break;
		}
		o[id]=false;
		upd(1,1,f,id,inf);
		int to;long long len;
		for(int i=pre[id];i;i=g[i].last)
		{
			to=g[i].to;
			len=g[i].len+p[x][id];
			if(o[to]&&len<p[x][to])
			{
				p[x][to]=len;
				upd(1,1,f,to,len);
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int x,y;
	f=m+n;
	int ki,ai;long long ti;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ki);
		for(int j=1;j<=ki;j++)
		{
			scanf("%d%lld",&ai,&ti);
			add(i+m,ai,ti);
			add(ai,i+m,ti);
		}
	}
	for(int i=1;i<=n;i++)
	{
		dj(i);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		ans=inf;
		long long sum=w[x]+w[y];
		for(int j=1;j<=n;j++)
		{
			if(p[j][x]!=inf&&p[j][y]!=inf)
			{
				ans=min(ans,p[j][x]+p[j][y]+sum);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
