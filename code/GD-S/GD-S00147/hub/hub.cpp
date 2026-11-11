#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,u,v,ans,sum;
bool flag[N],vis[N];
vector<int> e[N];
void dfs2(int u,int father)
{
	vis[u]=1;
	for(auto v : e[u])
	{
		if(v==father||!flag[v]) continue;
		dfs2(v,u);
	}
}
void dfs3(int u,int father,int dis)
{
	if(flag[u])
	{
		sum=max(sum,dis);
		return;
	}
	for(auto v : e[u])
	{
		if(v==father) continue;
		dfs3(v,u,dis+1);
	}
}
void dfs1(int depth,int lst)
{
	if(depth>k)
	{
		int cnt=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]&&!vis[i])
			{
				cnt++;
				dfs2(i,-1);
			}
		}
		if(cnt!=2) return;
		sum=0;
		for(int i=1;i<=n;i++) dfs3(i,-1,0);
		ans=min(ans,sum);
		return;
	}
	for(int i=lst+1;i<=n+depth-k;i++) flag[i]=1,dfs1(depth+1,i),flag[i]=0;
}
void solve()
{
	scanf("%d%d",&n,&k),ans=1e9;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}
