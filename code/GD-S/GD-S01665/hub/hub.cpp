#include<bits/stdc++.h>
using namespace std;
struct E
{
	int nex;
	int to;
}e[2000005];
int h[1000005],bs;
void add(int x,int y)
{
	e[++bs]={h[x],y};
	h[x]=bs;
}
int xz[1000005],ans;
int f[1000005],bz[1000005];
int len[1000005],rd[1000005];
int n,k;
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void bf(int x,int y)
{
	if(y>k) return;
	if(x>n)
	{
		for(int i=1;i<=n;i++) f[i]=i,bz[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(xz[i])
			{
				for(int j=h[i];j;j=e[j].nex)
				{
					int u=e[j].to;
					if(xz[u]) f[find(u)]=find(i);
				}
			}
		}
		int tt=0;
		for(int i=1;i<=n;i++)
		{
			if(xz[i]&&!bz[find(i)])
			{
				bz[find(i)]=1;
				tt++;
			}
		}
		for(int i=1;i<=n;i++) bz[i]=0;
		if(tt>2) return;
		queue<array<int,2> > q;
		for(int i=1;i<=n;i++)
		{
			if(xz[i]) q.push({i,0}),bz[i]=1;
		}
		if(q.empty()) return;
		int w=0;
		while(!q.empty())
		{
			array<int,2> p=q.front();
			q.pop();
			int x=p[0],b=p[1];
			w=max(w,b);
			for(int i=h[x];i;i=e[i].nex)
			{
				int u=e[i].to;
				if(!bz[u])
				{
					bz[u]=1;
					q.push({u,b+1});
				}
			}
		}
		ans=min(ans,w);
	}
	else
	{
		xz[x]=1;
		bf(x+1,y+1);
		xz[x]=0;
		bf(x+1,y);
	}
}
int wow[1000005];
int check(int mid)
{
	int qwq=0;
	for(int i=1;i<=n;i++)
	{
		rd[i]=0;
		for(int j=h[i];j;j=e[j].nex) rd[i]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		len[i]=0;
		if(rd[i]==1) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(len[x]==mid){wow[++qwq]=x;continue;}
		for(int i=h[x];i;i=e[i].nex)
		{
			int u=e[i].to;
			rd[u]--;
			if(rd[u]==1) q.push(u);
			if(!rd[u]) continue;
			len[u]=max(len[u],len[x]+1);
		}
	}
	if(qwq>2) return 0;
	if(qwq<2) return 1;
	for(int i=1;i<=n;i++) bz[i]=0;
	queue<array<int,2> > Q;
	Q.push({wow[1],0}),bz[wow[1]]=1;
	Q.push({wow[2],0}),bz[wow[2]]=1;
	int w=0;
	while(!Q.empty())
	{
		array<int,2> p=Q.front();
		Q.pop();
		int x=p[0],b=p[1];
		w=max(w,b);
		for(int i=h[x];i;i=e[i].nex)
		{
			int u=e[i].to;
			if(!bz[u])
			{
				bz[u]=1;
				Q.push({u,b+1});
			}
		}
	}
	return w<=mid;
}
void solve()
{
	scanf("%d%d",&n,&k);
	ans=1e9,bs=0;
	for(int i=1;i<=n;i++) h[i]=0;
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	if(k==2)
	{
		int l=0,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
	}
	else bf(1,0);
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve(); 
}
