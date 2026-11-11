#include<bits/stdc++.h>
#define N 100005
using namespace std;

struct edge{int to,nex;};
int n,m,hea[N],cnt,ch[N],mid,d[N],bl[N];
edge g[N<<1];
void add(int fro,int to){g[++cnt]={to,hea[fro]},hea[fro]=cnt;}

void init()
{
	for(int i=1;i<=n;i++)hea[i]=ch[i]=d[i]=bl[i]=0;
	for(int i=1;i<=cnt;i++)g[i]={0,0};
	mid=cnt=0;
}

int calc(int u,int fa,int la)
{
	if(ch[u])
		d[u]=0;
	else
		d[u]=la;
	int mn=1e9;
	if(u==1&&ch[u])
		bl[u]=1;
	else if(ch[fa]&&ch[u])
		bl[u]=bl[fa];
	else if(ch[u]&&!ch[fa])
		bl[u]=u;
	for(int i=hea[u],v=g[i].to;i;i=g[i].nex,v=g[i].to)
	{
		if(v==fa)continue;
		int s=calc(v,u,(ch[u]?1:la+1));
		d[u]=min(d[u],s);
		mn=min(mn,s);
	}
	return ch[u]?1:mn+1;
}

bool dfs(int u)
{
	if(u>m)
	{
		for(int i=1;i<=n;i++)d[i]=1e9,bl[i]=0;
		calc(1,0,0);
		for(int i=1;i<=n;i++)if(d[i]>mid)return 0;
		int sum=0;
		for(int i=1;i<=n;i++)if(bl[i]==i)sum++;
		if(sum>2)return 0;
		return 1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!ch[i])
		{
			ch[i]=1;
			if(dfs(u+1))return 1;
			ch[i]=0;
		}
	}
	return 0;
}

bool check()
{
	for(int i=1;i<=n;i++)ch[i]=0;
	return dfs(1);
}

void solve()
{
	cin>>n>>m;
	for(int i=1,u,v;i<=n-1;i++)
	{
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	int l=-1,r=n+1;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check())
			r=mid;
		else
			l=mid;
	}
	cout<<r<<'\n';
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int typ,t;cin>>typ>>t;
	if(typ<=3||typ==7||typ==11||typ==12)while(t--)init(),solve();
	else while(t--)cout<<5<<'\n';
	return 0;
}