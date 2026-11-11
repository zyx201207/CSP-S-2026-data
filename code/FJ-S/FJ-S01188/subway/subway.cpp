#include<bits/stdc++.h>
using namespace std;
inline long long read();
inline void endl();
inline void kg();
const long long N=510,M=5e5+10,INF=1e13;
long long c,n,m,d,Q,w[M],l[N];
unordered_map< long long,long long> t[N];//路的编号,节点，站台时间  
//vector <long long> t[N];
struct node
{
	long long to,v;
};
vector <node> a[N];
vector <long long> g[M];
long long vis[N][N],dp[N][N];
bool ch[N];
inline void dij(int s,long long dis[])
{
	priority_queue<pair<long long,int> > q;
	pair<long long,int> p,temp;
	p.first=0,p.second=s;
	q.push(p),dis[s]=0;
	memset(ch,0,sizeof(bool)*(n+5));
	while(!q.empty())
	{
		p=q.top(),q.pop();
		int u=p.second,val=-p.first,v;
		if(ch[u]) continue;
		ch[u]=1;
		int len=a[u].size();
		for(int i=0;i<len;i++)
		{
			v=a[u][i].to;
			if(dis[v]>dis[u]+a[u][i].v)
			{
				dis[v]=dis[u]+a[u][i].v;
				temp.first=-dis[v],temp.second=v;
				q.push(temp);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("ans.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(long long i=1;i<=m;i++) w[i]=read();
	for(long long i=1;i<=n;i++)
	{
		l[i]=read();
		for(long long j=1;j<=l[i];j++)
		{
			long long x=read();
//			pair<long long,long long> p;
//			p.first=i,p.second=read();
//			t[p]=read();
			t[i][x]=read();
			g[x].push_back(i);
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++) vis[i][j]=dp[i][j]=INF;
		dp[i][i]=vis[i][i]=0;
	}
//	cout<<vis[1][1];
	long long u,v;
	for(long long i=1;i<=m;i++)
	{
		long long len=g[i].size();
		for(long long j=0;j<len;j++)
		{
			for(long long k=j+1;k<len;k++)
			{
				u=g[i][j],v=g[i][k];
				pair<long long,long long> x,y;
				x.first=u,y.first=v,x.second=y.second=i;
				long long p=t[x.first][x.second]+t[y.first][y.second];
				vis[u][v]=min(vis[u][v],p);
				vis[v][u]=min(vis[v][u],p);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		node p;
		for(int j=i+1;j<=n;j++)
		{
			if(vis[i][j]==INF) continue;
			p.to=j,p.v=vis[i][j];
			a[i].push_back(p);
			p.to=i;
			a[j].push_back(p);
		}
	}
	//	for(long long i=1;i<=n;i++)
//	{
//		long long len=a[i].size();
//		cout<<i<<":\n";
//		for(long long j=0;j<len;j++)
//		{
//			node p=a[i][j];
//			cout<<p.to<<','<<p.v;
//		}
//		endl();
//	}
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long j=1;j<=n;j++)
//		{
//			dp[i][j]=min(dp[i][j],vis[i][j]);
//		}
////		endl();
//	}
	for(int i=1;i<=n;i++)
	{
		dij(i,dp[i]);
	}
//	for(long long k=1;k<=n;k++)
//	{
//		for(long long i=1;i<=n;i++)
//		{
//			dp[i][i]=0;
//			for(long long j=1;j<=n;j++)
//			{
//				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
////				if(dp[i][j]<0) return 114514;
////				cout<<i<<' '<<j<<' '<<k<<endl;
//			}
//		}
//	}
//	for(long long i=1;i<=n;i++) for(long long j=1)
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long j=1;j<=n;j++)
//		{
//			cout<<dp[i][j]<<' ';
//		}
//		endl();
//	}
//	endl(),endl();
	long long ans=1e13,add;
	while(Q--)
	{
		ans=1e13,add=0;
		long long x=read(),y=read(),u,v;
		long long l1=g[x].size(),l2=g[y].size();
		if(x==y)
		{
			cout<<"0\n";
			continue;
		}
		add=w[x]+w[y];
		for(long long i=0;i<l1;i++)
		{
			for(long long j=0;j<l2;j++)
			{
				u=g[x][i],v=g[y][j];
				pair<long long,long long> p1,p2;
				p1.first=u,p2.first=v;
				p1.second=x,p2.second=y;
				ans=min(ans,t[p1.first][p1.second]+t[p2.first][p2.second]+dp[u][v]);
			}
		}
//		cout<<ans<<' '<<add<<endl;
		cout<<(long long)(ans+add);endl();
	}


	return 0;
}
inline long long read()
{
	long long f=1;
	long long num=0;
	char x=getchar();
	while(x<'0'||x>'9')
	{
		if(x=='-') f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9')
	{
		num=num*10+(x-'0');
		x=getchar();
	}
	return f*num;
}
inline void endl()
{
	puts("");
	return ;
}
inline void kg()
{
	putchar(' ');
}


