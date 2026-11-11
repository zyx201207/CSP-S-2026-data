#include<bits/stdc++.h>
#define il inline
#define int long long
#define pii pair<int,int>

using namespace std;
const int maxn=5e2+5,maxm=2e5+5;
int cnt,n,m,c,d,q,w[maxm],hh[maxm<<1],dis[maxn][maxm],jul[maxm<<1];
bool vis[maxm<<1];
struct node
{
	int wei,to,nex;
}edg[maxm<<2];
struct queu
{
	int num,id;
	operator < (const queu &x) const
	{
		return num>x.num;
	}
}; 
il int read()
{
	int res,f=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')
		if(ch=='-')
			f=-1;
	res=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res*f;
}
il void add(int x,int y,int z)
{
	edg[++cnt].nex=hh[x];
	edg[hh[x]=cnt].to=y;
	edg[cnt].wei=z;
	edg[++cnt].nex=hh[y];
	edg[hh[y]=cnt].to=x;
	edg[cnt].wei=z;
}
il void zdl(int sta)
{
	for(int i=1;i<=m+n;i++)
	{
		vis[i]=0;
		jul[i]=0x3f3f3f3f;
	}
	priority_queue<queu> dui;
	dui.push({0,sta});
	vis[sta]=1;
	jul[sta]=0;
	while(!dui.empty())
	{
		int now=dui.top().id;
		vis[dui.top().id]=1;
		dui.pop();
		for(int i=hh[now];i;i=edg[i].nex)
			if(!vis[edg[i].to]&&jul[edg[i].to]>jul[now]+edg[i].wei)
			{
				jul[edg[i].to]=jul[now]+edg[i].wei;
				dui.push((queu){jul[edg[i].to],edg[i].to});
			}
		while(!dui.empty()&&vis[dui.top().id])
			dui.pop();
	}
	for(int i=1;i<=m;i++)
		dis[sta-m][i]=jul[i];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		for(int j=1;j<=x;j++)
		{
			int y=read(),z=read();
			add(m+i,y,z);
		}
	}
	for(int i=1;i<=n;i++)
		zdl(m+i);
	while(q--)
	{
		int x=read(),y=read(),ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
			ans=min(ans,dis[i][x]+dis[i][y]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}

