#include<bits/stdc++.h>
using namespace std;
long long w[500010];
long long a[30];
long long t[30];
long long head[1000010];
long long nxt[1000010];
long long to[1000010];
long long val[1000010];
long long tot;
void add(long long x,long long y,long long z)
{
	to[++tot]=y;
	val[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct rec
{
	long long num,id;
	bool operator < (const rec& x)const
	{
		return num>x.num;
	}
};
priority_queue<rec>q;
long long dis[500010];
void dijkstra(long long s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(rec{0,s});
	while(!q.empty())
	{
		long long x=q.top().id;
		q.pop();
		for(long long i=head[x];i;i=nxt[i])
		{
			long long y=to[i];
			if(dis[x]+val[i]<dis[y])
			{
				dis[y]=dis[x]+val[i];
				q.push(rec{dis[y],y});
			}
		}
	}
}
long long read()
{
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	long long ret=0;
	while(isdigit(ch))
	{
		ret=ret*10+(ch-'0');
		ch=getchar();
	}
	return ret;
}
void write(long long x)
{
	if(x<10)
	{
		putchar(x+'0');
		return ;
	}
	write(x/10);
	putchar(x%10+'0'); 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c=read(),n=read(),m=read(),d=read(),q=read();
	for(long long i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(long long i=1;i<=n;i++)
	{
		long long k=read();
		for(long long j=1;j<=k;j++)
		{
			a[j]=read();
			t[j]=read();
		}
		for(long long j=1;j<k;j++)
		{
			for(long long x=j+1;x<=k;x++)
			{
				add(a[x],a[j],t[j]+t[x]);
				add(a[j],a[x],t[j]+t[x]);
			}
		}
	}
	while(q--)
	{
		long long x=read(),y=read();
		dijkstra(x);
		write(dis[y]+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
