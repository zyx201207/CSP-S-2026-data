#include <iostream>
#include <cstring>
using namespace std;

const int N=505;
const int M=5e5+5; 
const int Q=1e5+5;
const int D=(M<<1)+N;
const int E=D<<2;

int c,n,m,d,q;
int W[M],k[N];
int aij,tij;

int h[D],v[E],w[E],nxt[E],cntT;

void add(int U,int V,int W)
{
	cntT++;
	v[cntT]=V;
	w[cntT]=W;
	nxt[cntT]=h[U];
	h[U]=cntT;
}

int id1(int x){ return x; }
int id2(int x){ return m+x; }

struct node
{
	int u,w;
};
bool cmp(node a,node b)
{
	return a.w<b.w;
}

struct heap
{
	node hp[D<<1];
	int hl;
	heap()
	{
		hl=0;
		memset(hp,0,sizeof hp);
	}
	void push(int x,int y)
	{
		hp[++hl].u=x;
		hp[hl].w=y;
		int idx=hl;
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
		int idx=1;
		while(true)
		{
			int mini=idx;
			int lft=(idx<<1);
			int rgt=(idx<<1)|1;
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
int dis[D];
void dij(int s)
{
	h1.clr();
	memset(dis,0x3f,sizeof dis);
	h1.push(s,0);
	dis[s]=0;
	while(h1.nmt())
	{
		node cur=h1.top();
		h1.pop();
		int u=cur.u;
		if(dis[u]!=cur.w)
		{
			continue;
		}
		for(register int i=h[u];i;i=nxt[i])
		{
			if(dis[v[i]]>dis[u]+w[i])
			{
				dis[v[i]]=dis[u]+w[i];
				h1.push(v[i],dis[v[i]]);
			}
		}
	}
}

struct qry
{
	int x,y,id;
}qy[Q];

bool cmp(qry a,qry b)
{
	return a.x<b.x;
}

void qs(int s,int e)
{
	if(s>=e) return ;
	qry mid=qy[(s+e)>>1];
	int l=s,r=e;
	while(l<=r)
	{
		while(cmp(qy[l],mid)) l++;
		while(cmp(mid,qy[r])) r--;
		if(l<=r)
		{
			swap(qy[l],qy[r]);
			l++,r--;
		}
	}
	qs(s,r);
	qs(l,e);
}

int ans[Q];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	
	cin>>c>>n>>m>>d>>q;
	for(register int i=1;i<=m;i++) cin>>W[i];
	
	for(register int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(register int j=1;j<=k[i];j++)
		{
			cin>>aij>>tij;
			add(id1(aij),id2(i),tij);
			add(id2(i),id1(aij),tij);
		}
	}
	for(register int i=1;i<=q;i++)
	{
		cin>>qy[i].x>>qy[i].y;
		qy[i].id=i;
	}
	qs(1,q);
	for(register int i=1;i<=q;i++)
	{
		if(qy[i].x!=qy[i-1].x) dij(qy[i].x);
		ans[qy[i].id]=dis[qy[i].y]+W[qy[i].x]+W[qy[i].y];
	}
	for(register int i=1;i<=q;i++)
	{
		cout<<ans[i]<<'\n';
	}
	return 0;
}
