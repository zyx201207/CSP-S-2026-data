#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

const int N=5e2,M=5e5,E=(M<<1);
const int M1=1e3+N,M2=5e5+N;
const long long inf=2e18;

int c,n,m,d,q;
int w[M+1];

int tot=1,beg[M+N+1],nxt[E+1],to[E+1],val[E+1];
inline void add(int x,int y,int v)
{
	nxt[tot]=beg[x],to[tot]=y,val[tot]=v;
	beg[x]=tot++;
	return;
}

struct node
{
	int pos; long long dis;
	friend bool operator<(const node& a,const node& b)
	{
		return a.dis>b.dis;
	}
};
long long dis[M1+1][M1+1]; bool vis[M+N+1];
inline void solve1()
{
	priority_queue<node> q;
	for(int st=1;st<=m;st++)
	{
		for(int i=1;i<=m+n;i++) dis[st][i]=inf,vis[i]=false;
		
		q.push({st,dis[st][st]=0});
		while(!q.empty())
		{
			int pos=q.top().pos; q.pop();
			if(vis[pos]) continue;
			
			vis[pos]=true;
			for(int i=beg[pos];i;i=nxt[i])
			{
				int s=to[i],v=val[i];
				
				if(dis[st][s]>dis[st][pos]+v)
				{
					dis[st][s]=dis[st][pos]+v;
					if(!vis[s]) q.push({s,dis[st][s]});
				}
			}
		}
	}
	
	return;
}

long long f[M2+1];
inline void solve2(int st)
{
	priority_queue<node> q;
	for(int i=1;i<=m+n;i++) f[i]=inf,vis[i]=false;
	
	q.push({st,f[st]=0});
	while(!q.empty())
	{
		int pos=q.top().pos; q.pop();
		if(vis[pos]) continue;
		
		vis[pos]=true;
		for(int i=beg[pos];i;i=nxt[i])
		{
			int s=to[i],v=val[i];
			
			if(f[s]>f[pos]+v)
			{
				f[s]=f[pos]+v;
				if(!vis[s]) q.push({s,f[s]});
			}
		}
	}
	
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,t; cin>>x>>t;
			add(m+i,x,t),add(x,m+i,t);
		}
	}
	
	if(c<=11)
	{
		solve1();
		while(q--)
		{
			int x,y; cin>>x>>y;
			cout<<w[x]+dis[x][y]+w[y]<<'\n';
		}
	}
	else if(c<=19)
	{
		while(q--)
		{
			int x,y; cin>>x>>y; solve2(x);
			cout<<w[x]+f[y]+w[y]<<'\n';
//			cout<<f[x]<<' '<<f[y]<<'\n'; cout<<w[x]<<' '<<w[y]<<'\n';
		}
	}
	else
	{
		solve1();
		while(q--)
		{
			int x,y; cin>>x>>y;
			cout<<w[x]+dis[x][y]+w[y]<<'\n';
		}
	}
	
	
	return 0;
}
/*
15 1 3 0 2
4 5 2
3 1 2 2 2 3 2
1 3
2 3
*/
