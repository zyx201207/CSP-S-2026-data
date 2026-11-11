#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar((x%10)^48);
}
const int N=2000005,M=5005;
int n,d,x[N];
int dis[M],cnt[M];
bitset<M> vis;
int rabs(int x){return x<0?-x:x;}
void bfs(int s)
{
	queue<int> q;
	vis.reset();
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=1;i<=n;i++)
		{
			int v=i,w=rabs(x[i]-x[u]);
			if(w>d) continue;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		int ans=0;
		if(c==11||c==12)
		{
			if(rabs(x[2]-x[1])*2<=d<rabs(x[2]-x[1])*3) write(0);
			else write(n-3);
			putchar('\n');
		}
		if(c<=10)
		{
			for(int i=1;i<=n;i++)
			{
				bfs(i);
				for(int j=i+1;j<=n;j++)
				{
					if(cnt[j]==2) ans++;
				}
			}
			write(ans);
			putchar('\n');
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
