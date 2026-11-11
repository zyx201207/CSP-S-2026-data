//廝__wanghc__、__NightDay__、chen_14514、void_ghost、EternalArcana CSP RP++

#include<bits/stdc++.h>
using namespace std;

#define write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define __wanghc__ cout.tie(0);

//#define ll long long

const int N=2e6+10;
int c,t,n,d;
int a[N];
int minn=0x3f3f3f3f;
vector<int> g[N]; 
bool vis[N];

int mindis;
inline void dfs(int u,int v,int step)
{
	if(step>mindis) return;
	if(u==v)
	{
		mindis=min(mindis,step);
		return;
	}
	for(int i:g[u])
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(i,v,step+1);
			vis[i]=0;
		}
	}
	return;
}

queue<pair<int,int> > q;
bool vis1[N];
inline int bfs(int u,int v)
{
	int cnt=0;
	q.push(make_pair(u,0));
	while(!q.empty())
	{
		int now=q.front().first,step=q.front().second;
		q.pop();
		vis1[now]=1;
		if(step==mindis && now==v) cnt++;
		for(int i:g[now])
		{
			if(!vis[i])
			{
				q.push(make_pair(i,step+1));
				vis[i]=1;
			}
		}
	}
	return cnt;
}

inline bool check(int u,int v)
{
	memset(vis,0,sizeof(vis));
	memset(vis1,0,sizeof(vis1));
	mindis=0x3f3f3f3f;
	dfs(u,v,0);
	int ans=bfs(u,v);
	if(ans==2) return 1;
	else return 0;
}

int main()
{
	write by __wanghc__
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
				if(abs(a[v]-a[u])<=d) g[u].push_back(v);
		}
		int ans=0;
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				if(check(u,v)) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
