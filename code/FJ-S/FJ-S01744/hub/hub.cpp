#include<bits/stdc++.h>
#define into(x1,x2) push(make_pair(x1,x2))
using namespace std;
const int N = 1e6 + 33;
int c,T,n,k,c1,c2,dep[N];
int lr[N],ff[N];
vector<int>v[N];
vector<int>son[N];
vector<int>s;
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	ff[u]=fa;
	for(int i:v[u])
	{
	  if(i==fa) continue;
	  son[u].push_back(i);
	  dfs(i,u);
	  lr[u]=max(lr[u],lr[i]+1);
	}
}
int ans,o;
int vis[N],vvs[N],dis[N],pp;
priority_queue<pair<int,int>>q;
int jk[N],cnt,ksk,lcnt;
int bfs()
{
	pp++;cnt=0;lcnt=0;
	for(int i=1;i<=n;i++) dis[i]=0;
	for(int i:s) vvs[i]=pp,jk[++cnt]=i;
	ksk=0;
	while(lcnt<cnt)
	{
	  lcnt++;
	  for(int i:v[jk[lcnt]])
	    if(pp!=vvs[i])
	      vvs[i]=pp,jk[++cnt]=i,dis[i]=dis[jk[lcnt]]+1;
	  ksk=max(ksk,dis[jk[lcnt]]);
	}
	return ksk;
}
int op,ylr[N];
void dfs2(int u,int fa)
{
	ylr[u]=lr[u];
	for(int i:v[u])
	{
	  if(i==fa) continue;
	  dfs(i,u);
	  lr[u]=max(lr[u],lr[i]+1);
	}
}
void dfs3(int u,int fa)
{
	lr[u]=ylr[u];
	for(int i:v[u])
	{
	  if(i==fa) continue;
	  dfs(i,u);
	}
}
void solve()
{
	ans=33333333;
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=n;j++)
	  {
	  	while(!q.empty()) q.pop();
	    if(i==j) continue;
		o=k-2;
		s.clear();
		s.push_back(i);
		s.push_back(j);
		if(o!=0)
		{
		  dfs2((dep[i]<dep[j]?i:j),ff[(dep[i]<dep[j]?i:j)]);
		  op++;
	      for(int p:son[i]) 
		  q.into(lr[p],p),vis[p]=op;
	      for(int p:son[j]) 
		    if(vis[p]!=op) 
		      q.into(lr[p],p),vis[p]=op;
	      while(o && !q.empty())
	      {
	        int now=q.top().second;
	        s.push_back(now);
	        q.pop();
	        for(int p:son[now])
	          if(vis[p]!=op)
	            q.into(lr[p],p),vis[p]=op;
	        o--;
	  	  }
		  dfs3((dep[i]<dep[j]?i:j),ff[(dep[i]<dep[j]?i:j)]);
		}
		if(o!=0)continue;
		ans=min(ans,bfs());
	  }
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--)
	{
	  memset(lr,0,sizeof lr);
	  for(int i=1;i<=n;i++)
	    v[i].clear(),son[i].clear();
	  cin>>n>>k;
	  for(int i=1;i<n;i++)
	  {
		cin>>c1>>c2;
		v[c1].push_back(c2);
		v[c2].push_back(c1);
	  }
	  dfs(1,0);
	  solve();
	}
	return 0;
}
/*
0 1
6 5
1 2
2 5
4 5
5 3
3 6
*/