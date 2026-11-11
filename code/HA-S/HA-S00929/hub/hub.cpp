#include <bits/stdc++.h>
using namespace std;
int C,T;
int n,k;
vector<int>G[1000010];
bool fg1[110];
int ans;
int dist[110];
int check(int rt,int fa)
{
	int cnt=fg1[rt];
	for(int to:G[rt])
	{
		if(to==fa) continue;
		cnt+=check(to,rt);
		if(fg1[to]&&fg1[rt]) cnt--;
	}
	return cnt;
}
void calc1(int rt,int fa)
{
	dist[rt]=(fg1[rt]?0:1e9);
	for(int to:G[rt])
	{
		if(to==fa) continue;
		calc1(to,rt);
		dist[rt]=min(dist[rt],dist[to]+1);
	}
}
void calc2(int rt,int fa)
{
	if(fa) dist[rt]=min(dist[rt],dist[fa]+1);
	for(int to:G[rt])
	{
		if(to==fa) continue;
		calc2(to,rt);
	}
}
void dfs(int i,int j)
{
	if(!j)
	{
		if(check(1,0)>2) return;
		calc1(1,0);
		calc2(1,0);
		int tmp=0;
		for(int i=1;i<=n;i++)
			tmp=max(tmp,dist[i]);
		ans=min(ans,tmp);
		return;
	}
	if(i>n) return;
	fg1[i]=1;
	dfs(i+1,j-1);
	fg1[i]=0;
	dfs(i+1,j);
}
void solve1()
{
	dfs(1,k);
	cout<<ans<<'\n';
}

void solve2()
{
	
}
void Clear()
{
	ans=1e9;
	for(int i=1;i<=n;i++) G[i].clear();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		Clear();
		for(int i=1;i<n;i++)
		{
			int u,v; cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(C<=3) solve1();
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
