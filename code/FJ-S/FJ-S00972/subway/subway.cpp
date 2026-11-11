#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],t[501][500001],las,S,T,final;
struct lne{int id,las;};
vector<lne>g[500001];
struct state{int u,fa,laid,used;};
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int bfs(int u,int fa,int laid,int used)
{
	queue<state>qu;
	qu.push({u,fa,laid,used});
	while(!qu.empty())
	{
		state p=qu.front();
		qu.pop();
		int u=p.u,fa=p.fa,laid=p.laid,used=p.used;
		if(u==T) {final=laid;return used;}
		for(lne i:g[u])
		{
			int line=i.id,v=i.las;
			if(v==fa) continue;
			if(line!=laid&&fa==0) qu.push({v,u,line,used+t[line][u]-t[laid][S]});
			else if(line!=laid) qu.push({v,u,line,used+t[laid][u]+t[line][u]});
			else qu.push({v,u,laid,used});
		}
	}
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,a;i<=n;i++)
	{
		a=read();
		las=0;
		for(int j=1,u,v;j<=a;j++) 
		{
			u=read(),v=read();
			t[i][u]=v;
			if(las!=0) g[u].push_back({i,las}),g[las].push_back({i,u});
			las=u;
		}
	}
	for(int i=1;i<=q;i++)
	{
		S=read(),T=read();
		int ln=g[S][0].id;
		write(bfs(S,0,ln,w[S]+w[T]+t[ln][S]+t[final][T])),putchar('\n');
	}
	return 0;
}
