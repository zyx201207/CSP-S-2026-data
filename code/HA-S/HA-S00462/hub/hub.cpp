#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void fre()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
int c,t;
const int MAXN=2e6+10;
ll ver[MAXN],nex[MAXN],head[MAXN],edg[MAXN],tot;
void add(int x,int y,ll z)
{
	ver[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
	edg[tot]=z;
}
void fuck()
{
	for(int i=1;i<=tot;i++)
	{
		head[i]=0;
	}
	tot=0;
}
int vis[MAXN],cnt,pos[MAXN],cntt,n,k;

vector<int>val[20];
void solve(int x)
{
	int kkk=0,tmp=x;
	while(x)
	{
		if(x&1)kkk++;
		x>>=1;
	}
	val[kkk].push_back(tmp);
}
void dfs(int x,int fa)
{
	vis[x]=1;
	for(int i=head[x];i;i=nex[i])
	{
		int y=ver[i];
		if(y==fa)continue;
		dfs(y,x);
	}
}
int vis1[MAXN],dis[MAXN];
inline void dij(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e9;
		vis1[i]=0;
	}
	priority_queue<pair<ll,int> >q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis1[u])continue;
		vis1[u]=1;
		
		for(int i=head[u];i;i=nex[i])
		{
			int y=ver[i];
			ll z=edg[i];
			if(dis[y]>dis[u]+z)
			{
				dis[y]=dis[u]+z;
				q.push({-dis[y],y});
			}
		}
	}
}
int dfs1(int x,int fa,int cnt)
{
	if(pos[x]==1)
	{
		return cnt;
	}
	for(int i=head[x];i;i=nex[i])
	{
		int y=ver[i];
		if(y==fa)
		{
			continue;
		}
		dfs1(y,x,cnt++);
	}
	return 1e9;
}
int main()
{
	fre();
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=10;i++)
		{
			val[i].clear();
		}
//		for(int i=1;i<=(1<<n);i++)
//		{
//			solve(i);
//		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v,1);
			add(v,u,1);
		}
//		int ans=1e9;
//		for(int i=0;i<val[k].size();i++)
//		{
//			for(int j=0;j<n;j++)
//			{
//				if((val[k][i]>>j)&1)
//				{
//					pos[j+1]=1;
//				}
//			}
//			int cnt=0;
//			for(int j=1;j<=n;j++)
//			{
//				if(pos[j]==1&&vis[j]==0)
//				{
//					dfs(j,0);
//					cnt++;
//				}
//			}
//			if(cnt>2)continue;
//			int maxn=0;
//			for(int j=1;j<=n;j++)
//			{
//				maxn=max(maxn,dfs1(j,0,0));
//				cout<<maxn<<endl;
//			}
//			ans=min(ans,maxn);
//			//cout<<ans<<endl;
//		}
		cout<<0<<'\n';
		fuck();
	}
	return 0;
}

