#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,cnt,x[N],y[N],head[N],fa[N],dis[15][15];
struct Node
{
	int next,v;
}e[N];
void add(int x,int y)
{
	e[++cnt].next=head[x];
	e[cnt].v=y;
	head[x]=cnt;
}
void init()
{
	cnt=0;
	for(int i=0;i<=2000000;i++) e[i].next=e[i].v=0,head[i]=0;
}
int find(int x)
{
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
void dfs(int now,int x,int fa)
{
	for(int i=head[x];i;i=e[i].next)
	{
		int y=e[i].v;
		if(y==fa) continue;
		dis[now][y]=dis[now][x]+1;
		dfs(now,y,x);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		init();
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>x[i]>>y[i];
			add(x[i],y[i]);
			add(y[i],x[i]);
		}
		for(int i=1;i<=n;i++) dfs(i,i,0);
		int zd=pow(2,n-1)-1,hhh=1e8;
		for(int i=1;i<=zd;i++)
		{
			int er[15],pp[15],tq[15],js=0,sl=0,td=i;
			bool pd[15];
			memset(er,0,sizeof(er));
			memset(pd,0,sizeof(pd));
			memset(pp,0,sizeof(pp));
			for(int j=1;j<=n;j++) fa[j]=j,tq[j]=1e8;
			while(td)
			{
				er[++js]=td%2;
				td/=2;
			}
			for(int j=1;j<n;j++) if(er[j]) merge(x[j],y[j]),pd[x[j]]=pd[y[j]]=1;
			for(int j=1;j<=n;j++) pp[find(j)]++;
			for(int j=1;j<=n;j++) if(pp[j]>1) sl++;
			if(sl>2) continue;
			cout<<i<<"\n";
			for(int j=1;j<=n;j++)
			{
				if(!pd[j]) continue;
				for(int k=1;k<=n;k++) tq[k]=min(tq[k],dis[j][k]);
			}
			int da=0;
			for(int j=1;j<=n;j++) da=max(da,tq[j]);
			hhh=min(hhh,da);
		}
		cout<<hhh<<"\n";
	}
	return 0;
}
