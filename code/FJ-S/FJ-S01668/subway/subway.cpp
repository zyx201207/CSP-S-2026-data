#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
int C,n,m,d,Q;
struct edge
{
	int to;
	long long v;
};
vector<edge> mp[N+M];
long long W[N],dis[N+M];
vector<long long> dist[N];
bool vis[N];
int sum=0;
queue<int> q;
void dfs(int x)
{
	q.push(x);
	dis[x]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=0;i<mp[now].size();i++)
		{
			int y=mp[now][i].to;
			if(dis[now]+mp[now][i].v<dis[y])
			{
				dis[y]=dis[now]+mp[now][i].v;
				q.push(y);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>C>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++)
		cin>>W[i],vis[i]=0;
	for(int i=1;i<=m;i++)
	{
		int k,u;
		long long t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>u>>t;
			mp[n+i].push_back((edge){u,t});
			mp[u].push_back((edge){n+i,t});
		}
	}
	while(Q--)
	{
		int S,T;
		cin>>S>>T;
		if(!vis[S])
		{
			for(int i=1;i<=n+m;i++) dis[i]=1e18;
			dfs(S);
			cout<<W[S]+dis[T]+W[T]<<endl;
			if(sum<=10005)
			{
				sum++,dist[S].push_back(0);
				for(int i=1;i<=n;i++) dist[S].push_back(dis[i]);
				vis[S]=1;
			}
		}
		else
			cout<<W[S]+dist[S][T]+W[T]<<endl;
	}
	return 0;
}

