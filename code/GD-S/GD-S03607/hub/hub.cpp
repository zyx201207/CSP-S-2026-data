#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,T;
int n,k;
vector<int> v[N];
int dep[N];
int sz[N];
int fa[N];
int maxson[N];
int top[N];
vector<int> point;
bool vis[N];
int clk=0;
int fvis[N];
ll ans=1e18;
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1;
	sz[u]=1;
	for(int i:v[u])
	{
		if(i==f)
			continue;
		fa[i]=u;
		dfs1(i,u);
		sz[u]+=sz[i];
		if(sz[maxson[u]] < sz[i])
			maxson[u]=i;
	}
}
void dfs2(int u,int head)
{
	top[u]=head;
	if(!maxson[u])
		return;
	dfs2(maxson[u],head);
	for(int i:v[u])
	{
		if(i==fa[u] or i==maxson[u])
			continue;
		dfs2(i,i);
	}
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]] < dep[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
	return (dep[x]<dep[y] ? x : y);
}
void ddfs(int u)
{
	fvis[u]=clk;
	for(int i:v[u])
	{
		if(vis[i] and fvis[i]!=clk)
			ddfs(i);
	}
}
bool flag()
{
	clk++;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i] and fvis[i]!=clk)
			ddfs(i),cnt++;
	}
	return (cnt<=2);
}
void dfs(int now,int kkk)
{
	if(kkk>k)
		return;
	if(now==n+1)
	{
		if(kkk!=k)
			return;
		if(!flag())
			return;
		ll num=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				continue;
			ll now=1e18;
//			cout<<i<<" #:\n";
			for(int j:point)
			{
				int lca=LCA(i,j);
				now=min(now,1ll*dep[i]+dep[j]-2*dep[lca]);
//				cout<<j<<" "<<lca<<" "<<1ll*dep[i]+dep[j]-2*dep[lca]<<"\n";
			}
			num=max(num,now);
		}
//		for(int t:point)
//			cout<<t<<" ";
//		cout<<"\n ###"<<num<<"\n";
		ans=min(ans,num);
		return;
	}
	dfs(now+1,kkk);
	point.push_back(now);
	vis[now]=1;
	dfs(now+1,kkk+1);
	point.pop_back();
	vis[now]=0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,0);
		dfs2(1,1);
		dfs(1,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			fa[i]=0;
			maxson[i]=0;
			dep[i]=0;
			top[i]=0;
			sz[i]=0;
		}
	}
	return 0;
}
/*
0 2
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
9 10
*/
