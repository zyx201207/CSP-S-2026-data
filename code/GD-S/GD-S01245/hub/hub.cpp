#include<bits/stdc++.h>
using namespace std;
int c,T;
const int N=1007;
int h[N],e[N],ne[N],idx;
int dis[N][N],n,k,uu[N],vv[N];
void add(int u,int v)
{
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx++;
}
int bz[N];
int f[N],st[N];
int find(int x)
{
	if(x==f[x])
	return x;
	return f[x]=find(f[x]);
}
void bfs(int x)
{
	dis[x][x]=0;
	for(int i=1;i<=n;i++)
	st[i]=0;
	st[x]=1;
	queue<int>q;
	q.push(x);
	while(q.size())
	{
		int xx=q.front();
		q.pop();
		for(int i=h[xx];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(st[j])
			continue;
			dis[x][j]=dis[x][xx]+1;
			q.push(j);
			st[j]=1;
		}
	}
}
int ans;
void dfs(int x,int y)
{
	if(y>k)
	return;
	if(x==n+1)
	{
		if(y==k)
		{
			for(int i=1;i<=n;i++)
			f[i]=i;
			int cnt=k-1;
			for(int i=1;i<n;i++)
			{
				if(bz[uu[i]]&&bz[vv[i]])
				{
					f[find(uu[i])]=find(vv[i]);
					cnt--;
				}
			}
			int l=0,r=0;
			int ok=1;
			for(int i=1;i<=n;i++)
			{
				if(bz[i]==0)
				continue;
				int now=find(i);
				if(l==0)
				{
					l=now;
					continue;
				}
				if(l==now)
				continue;
				
				ok=0;
			}
		
			if(ok)
			{
				
				int mx=0;
				for(int i=1;i<=n;i++)
				{
					if(bz[i]==1)
					continue;
					int res=1e9+7;
					for(int j=1;j<=n;j++)
					{
						if(bz[j]==1&&i!=j)
						{
							res=min(res,dis[i][j]);
						}
					}
					mx=max(mx,res);
				}
		
				ans=min(ans,mx);
			}
		}
		return ;
	}
	bz[x]=1;
	dfs(x+1,y+1);
	bz[x]=0;
	dfs(x+1,y);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=1e9+7;
		scanf("%d%d",&n,&k);
		cout<<n/2<<endl;
		continue;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			dis[i][j]=0;
		}
		memset(h,-1,sizeof(h));
		idx=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			uu[i]=u,vv[u]=v;
		}
		for(int i=1;i<=n;i++)
		bfs(i);
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
/*0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10*/


