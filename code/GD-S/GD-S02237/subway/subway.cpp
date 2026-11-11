#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e2+55;
int w[N];
bool vis[N];
vector<pair<int,int > >G[N];
int c,n,m,d,q,qwq,a,b,x,y,f,t,ans = 1e18;
int dis[N][25];
void dfs(int now,int fa,int cr,int us)
{
	if(now == t)
	{
		ans = min(ans,us + dis[now][cr]);
		return ;
	}
	for(auto v : G[now])
	{
		if(v.first == fa || vis[v.first])
		{
			continue;
		}
		vis[v.first] = 1;
		if(cr == -1)
		{
			dfs(v.first,now,v.second,us + dis[now][v.second]); 
		}
		else if(v.second == cr)
		{
			dfs(v.first,now,cr,us);
		}
		else
		{
			dfs(v.first,now,v.second,dis[now][cr] + dis[now][v.second] + us);
		}
		vis[v.first] = 0;
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>qwq>>a>>b;
		dis[a][i] = b;
		for(int j = 2;j<=qwq;j++)
		{
			int x,y;
			cin>>x>>y;	
			dis[x][i] = y;
			G[a].push_back({x,i});
			G[x].push_back({a,i});
			a = x;
		}	
	}
	while(q --)
	{
		memset(vis,false,sizeof(vis));
		ans = 1e18;
		cin>>f>>t;
		vis[f] = true;
		dfs(f,-1,-1,0);
		ans += w[f] + w[t];
		cout<<ans<<endl;
	}
	return 0;
}




