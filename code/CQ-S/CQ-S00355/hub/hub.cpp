#include<bits/stdc++.h>
using namespace std;
const int N=15,INF=1e9;
struct czc
{
	int id,d;
};
vector<int> edge[N];
int n,k,ans=INF,s[N],rl[N],vis[N];
queue<czc> q;
int find(int k)
{
	if(rl[k]==k) return k;
	return rl[k]=find(rl[k]);
}
void bfs()
{
	int total=0,cnt=0;
	for(int i=1;i<=n;i++) cnt+=vis[i];
	while(!q.empty())
	{
		czc first=q.front();
		q.pop();
		total=max(total,first.d);
		int len=edge[first.id].size();
		for(int i=0;i<len;i++)
		{
			int to=edge[first.id][i];
			if(!vis[to]) 
			{
				vis[to]=1;
				q.push({to,first.d+1});
			}
		}
	}
	ans=min(ans,total);
}
void check()
{
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=s[i],rl[i]=i;
	if(cnt!=k) return ;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		int len=edge[i].size();
		if(!s[i]) continue ;
		for(int j=0;j<len;j++)
		{
			int to=edge[i][j];
			if(to>i && s[to]) rl[i]=to;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!s[i]) continue ;
		if(find(i)==i) cnt++;
	}
	if(cnt>2) return ;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		if(s[i])
		{
			vis[i]=1;
			q.push({i,0});
		}
	}
	bfs();
}
void dfs(int k)
{
	if(k==n+1)
	{
		check();
		return ;
	}
	s[k]=1,dfs(k+1);
	s[k]=0,dfs(k+1);
}
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) edge[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v),edge[v].push_back(u);
	}
	ans=INF,dfs(1);
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve();
	
	return 0;
}
