#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int CID,T,n,k,h[N],tot,deg[N],d1[N],d2[N],f1[N],f2[N],mx,rt,len,l[N],cnt,a[N],ta;
vector<int> v[N];
struct edge{
	int v,nxt;
}g[N<<1];
void add(int u,int v)
{
	g[++tot]=(edge){v,h[u]};
	h[u]=tot;
	deg[u]++;
}
void dfs1(int u,int fa)
{
//	cout<<u<<endl;
	if(deg[u]==1&&fa)
	{
		d1[u]=0,f1[u]=u;
		return;
	}
	d1[u]=d2[u]=0;
	for(int i=h[u];i;i=g[i].nxt)
	{
		int v=g[i].v;
		if(v==fa) continue;
		dfs1(v,u);
		if(d1[v]+1>d1[u])
		{
			d2[u]=d1[u],f2[u]=f1[u];
			d1[u]=d1[v]+1,f1[u]=v;
		}
		else
		{
			if(d1[v]+1>d2[u])
			{
				d2[u]=d1[v]+1,f2[u]=v;
			}
		}
	}
	if(d1[u]+d2[u]>mx)
	{
		mx=d1[u]+d2[u];
		rt=u;
	}
}
void get_l(int u,int o)
{
//	cout<<u<<endl;
	if(o==0)
	{
		if(d1[u]) get_l(f1[u],1);
		l[++len]=u;
		if(d2[u]) get_l(f2[u],2);
	}
	if(o==1)
	{
		if(d1[u]) get_l(f1[u],1);
		l[++len]=u;
	}
	if(o==2)
	{
		l[++len]=u;
		if(d1[u]) get_l(f1[u],2); 
	}
}
void dfs2(int u,int fa1,int fa2)
{
	d1[u]=0;
	for(int i=h[u];i;i=g[i].nxt)
	{
		int v=g[i].v;
		if(v==fa1||v==fa2) continue;
		dfs2(v,u,fa2);
		d1[u]=max(d1[u],d1[v]+1);
	}
}
void dfs3(int u,int fa1,int fa2,int x,bool o)
{
	if(o&&d1[u]+1>x) cnt--;
	for(int i=h[u];i;i=g[i].nxt)
	{
		int v=g[i].v;
		if(v==fa1||v==fa2) continue;
		dfs3(v,u,fa2,x,1);
	}
}
bool check(int x)
{
	cnt=k;
	ta=0;
	a[++ta]=x+1;
	for(int i=x+2;i<=len-x-1;i++)
	{
		dfs2(l[i],l[i-1],l[i+1]);
		if(d1[l[i]]>=x)
		{
			dfs3(l[i],l[i-1],l[i+1],x,0);
			a[++ta]=i;
		}
	}
	a[++ta]=len-x;
	if(cnt<0) return 0;
	if(cnt>=len-(x<<1)) return 1;
	for(int i=x+1;i<=len-x;i++) v[i].clear();
	for(int i=x+2,j=1,k=a[1];i<=len-x;i++)
	{
		if(i>a[j+1]) k=max(k,a[++j]);
		if(len-x-i+1+k-x<=cnt) return 1;
		for(int l:v[i]) k=max(k,l);
		if(d1[l[i]]<x) v[i+x-d1[l[i]]].push_back(i-(x-d1[l[i]]));
	}
	return 0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>CID>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) h[i]=0;
		tot=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		mx=0;
		dfs1(1,0);
//		cout<<rt<<endl;
		len=0;
		get_l(rt,0);
		l[len+1]=0;
//		for(int i=1;i<=len;i++) cout<<l[i]<<" ";
//		cout<<endl;
//		cout<<check(0);
//		return 0;
//		cout<<check(6);
//		return 0;
		int lb=-1,ub=len-1>>1;
		while(lb+1<ub)
		{
			int mid=lb+ub>>1;
			if(check(mid)) ub=mid;
			else lb=mid;
		}
		cout<<ub<<"\n";
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

*/
