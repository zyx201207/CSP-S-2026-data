#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N=256,inf=1e18;
int c,t,n,k,ans;
bool chose[N],vis[N];
vector<int> e[N];
queue<pair<int,int> > Q;

void DFS_con(int u)
{
	vis[u]=true;
	for(int v:e[u]) if(chose[v] and !vis[v])
		DFS_con(v);
}

bool check()
{
	memset(vis,false,sizeof(vis));
	int res=0;
	For(i,n) if(chose[i] and !vis[i]) DFS_con(i),res++;
	return res<=2;
}

int BFS()
{
	memset(vis,false,sizeof(vis));
	int res=0;
	For(i,n) if(chose[i]) Q.push({i,0}),vis[i]=true;
	
	while(!Q.empty())
	{
		int u=Q.front().first,dis=Q.front().second;
		Q.pop();
		res=max(res,dis);
		for(int v:e[u]) if(!vis[v])
			Q.push({v,dis+1}),vis[v]=true;
	}
	return res;
}

void DFS_choose(int p,int cnt)
{
	if(cnt==k)
	{
		if(check())
			ans=min(ans,BFS());
		return;
	}
	Fors(i,p,n) if(!chose[i])
	{
		chose[i]=true;
		DFS_choose(i+1,cnt+1);
		chose[i]=false;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		For(i,n) e[i].clear();
		For(i,n-1)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n==k)
		{
			cout<<"0\n";
			continue;
		}
		ans=inf;
		DFS_choose(1,0);
		
		cout<<ans<<'\n';
	}
	return 0;
}
