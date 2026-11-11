#include <iostream>
#include <cstring>
using namespace std;

const int N=2e6+5;
const int E=N<<5;

int h[N],v[E],nxt[E],cntT;

void add(long long U,long long V)
{
	cntT++;
	v[cntT]=V;
	nxt[cntT]=h[U];
	h[U]=cntT;
}

struct node
{
	long long u,w;
};
bool cmp(node a,node b)
{
	return a.w<b.w;
}

struct heap
{
	node hp[N<<1];
	long long hl;
	heap()
	{
		hl=0;
		memset(hp,0,sizeof hp);
	}
	void push(long long x,long long y)
	{
		hp[++hl].u=x;
		hp[hl].w=y;
		long long idx=hl;
		while(idx>1&&cmp(hp[idx],hp[(idx>>1)]))
		{
			swap(hp[(idx>>1)],hp[idx]);
			idx>>=1;
		}
	}
	void pop()
	{
		swap(hp[1],hp[hl]);
		hl--;
		long long idx=1;
		while(true)
		{
			long long mini=idx;
			long long lft=(idx<<1);
			long long rgt=(idx<<1)|1;
			if(lft<=hl&&cmp(hp[lft],hp[mini]))
			{
				mini=lft;
			}
			if(rgt<=hl&&cmp(hp[rgt],hp[mini]))
			{
				mini=rgt;
			}
			if(mini==idx)
			{
				break;
			}
			swap(hp[mini],hp[idx]);
			idx=mini;
		}
	}
	bool nmt()
	{
		return hl;
	}
	void clr()
	{
		hl=0;
	}
	node top()
	{
		return hp[1];
	}
}h1;
long long dis[N];
long long g[N];
void dij(long long s)
{
	h1.clr();
	memset(g,0,sizeof g);
	memset(dis,0x3f,sizeof dis);
	h1.push(s,0);
	dis[s]=0;
	g[s]=1;
	while(h1.nmt())
	{
		node cur=h1.top();
		h1.pop();
		long long u=cur.u;
		if(dis[u]!=cur.w)
		{
			continue;
		}
		for(register int i=h[u];i;i=nxt[i])
		{
			if(dis[v[i]]>dis[u]+1)
			{
				dis[v[i]]=dis[u]+1;
				g[v[i]]=g[u];
				h1.push(v[i],dis[v[i]]);
			}
			else if(dis[v[i]]==dis[u]+1)
			{
				g[v[i]]+=g[u];
			}
		}
	}
}

long long c,t,n,d;
long long x[N];

void solve()
{
	cntT=0;
	memset(h,0,sizeof h);
	cin>>n>>d;
	for(register int i=1;i<=n;i++)
	{
		cin>>x[i];
		for(register int j=i-1;j;j--)
		{
			if(x[i]-x[j]>d) break;
			add(i,j);
			add(j,i);
		}
	}
	long long ans=0;
	for(register int i=1;i<n;i++)
	{
		dij(i);
		for(register int j=i+1;j<=n;j++)
		{
			if(g[j]==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(register int i=1;i<=t;i++)
	{
		solve();
	}
	
	return 0;
}
