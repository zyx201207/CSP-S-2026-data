#include <bits/stdc++.h>
using namespace std;
const int N=1e6+8;
int C,T,n,k,x,y,m,p1,p2,l,r,ans,dis[N],a[N],vis[N];
vector<int> v[N],d;
struct line
{
	int l,r;
	bool operator<(const line a) const
	{
		return l<a.l;
	}
}li[N];
void dfs(int x,int fa)
{
	dis[x]=dis[fa]+1;
	for(int i:v[x])	if(i!=fa)	dfs(i,x);
}
void get(int x,int y,int fa)
{
	d.push_back(x);
	if(x==y)	return;
	for(int i:v[x])	if(i!=fa)
	{
		get(i,y,x);
		if(d.back()==y)	break;
	}
	if(d.back()!=y)	d.pop_back();
}
void query(int x,int fa)
{
	dis[x]=0;
	for(int i:v[x])	if(i!=fa&&!vis[i])
	{
		query(i,x);
		dis[x]=max(dis[x],dis[i]+1);
	}
}
int check(int x)
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]>x)	return 0;
		li[i].l=max(1,i-(x-a[i]));
		li[i].r=min(m,i+(x-a[i]));
	}
	sort(li+1,li+m+1);
	int Cnt=0;
	for(int i=1,pos=0;i<=m;i++)
	{
		if(pos<li[i].l)
		{
			pos=li[i].r;
			Cnt++;
		}
	}
	if(Cnt<=k)	return 1;
	return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)	v[i].clear();
		for(int i=1;i<=n;i++)	vis[i]=0;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		p1=1;
		for(int i=2;i<=n;i++)	if(dis[i]>dis[p1])	p1=i;
		dfs(p1,0);
		p2=1;
		for(int i=2;i<=n;i++)	if(dis[i]>dis[p2])	p2=i;
		d.clear();
		get(p1,p2,0);
		m=d.size();
		for(int i:d)	vis[i]=1;
		for(int i=1;i<=m;i++)
		{
			query(d[i-1],0);
			a[i]=dis[d[i-1]];
		}
		l=0;r=n-1;ans=n;
		while(l<=r)
		{
			int m=(l+r)>>1;
			if(check(m))
			{
				ans=m;
				r=m-1;
			}
			else	l=m+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
