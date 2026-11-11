#include<bits/stdc++.h>
#define int long long
using namespace std;

int C,T,n,m,ex[15],ey[15];
int dis[15],fa[15];
bool vis[15];
vector<int> g[15];
queue<int> q;

void Init(){for(int i=0;i<n;i++) fa[i]=i;}
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
void Merge(int x,int y){fa[Find(x)]=Find(y);}

bool chk()
{
	Init();
	for(int i=1;i<n;i++)
		if(vis[ex[i]] && vis[ey[i]])
			Merge(ex[i],ey[i]);
	int kuai=0;
	for(int i=0;i<n;i++)
		if(vis[i] && Find(i)==i)
			kuai++;
	return kuai<=2;
}
int bfs()
{
	memset(dis,-1,sizeof(dis));
	for(int i=0;i<n;i++)
		if(vis[i]) dis[i]=0,q.push(i);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(auto y:g[x])
			if(dis[y]==-1)
				dis[y]=dis[x]+1,q.push(y);
	}
	int maxn=0;
	for(int i=0;i<n;i++) maxn=max(maxn,dis[i]);
	return maxn;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		for(int i=0;i<n;i++) g[i].clear();
		cin>>n>>m;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			x--;y--;
			g[x].push_back(y);
			g[y].push_back(x);
			ex[i]=x;ey[i]=y;
		}
		int ans=n;
		for(int msk=0;msk<1<<n;msk++)
		{
			if(__builtin_popcount(msk)!=m) continue;
			for(int i=0;i<n;i++) vis[i]=(msk>>i)&1;
			if(chk()) ans=min(ans,bfs());
		}
		cout<<ans<<'\n';
	}
	return 0;
}
