#include<bits/stdc++.h>
using namespace std;
const int N=4444;
int c,t,n,k,u,v,sub[N],mn=1000000000,vis[N],dis[N][N],vis2[N];
vector<int>mp[N];
void init(int bg,int u,int fa,int ds)
{
	dis[bg][u]=ds;
	for (int i=0;i<(int)mp[u].size();i++)
	{
		if (mp[u][i]==fa) continue;
		init(bg,mp[u][i],u,ds+1);
	}
}
void bfs(int s,int ln)
{
	queue<int>q;
	map<int,int>ma;
	q.push(s);
	vis2[s]=1;
	for (int i=1;i<=ln;i++) ma[sub[i]]=1;
	while (!q.empty())
	{
		int f=q.front();q.pop();
		for (int i=0;i<(int)mp[f].size();i++)
		{
			if ((!vis2[mp[f][i]])&&ma[mp[f][i]])
			{
				vis2[mp[f][i]]=1;
				q.push(mp[f][i]);
			}
		}
	}
}
int calc(int len)
{
	int sum=0;
	memset(vis2,0,sizeof(vis2));
	for (int i=1;i<=len;i++)
	{
		if (!vis2[sub[i]])
		{
			sum++;
			bfs(sub[i],len);
		}
	}
	return sum;
}
void dfs(int dep,int sl)
{
	if (dep==n+1)
	{
		if (calc(sl)<=2)
		{
			int com,rr=-1;
			for (int i=1;i<=n;i++)
			{
				com=1000000000;
				for (int j=1;j<=sl;j++)
				{
					com=min(com,dis[i][j]);
				}
				rr=max(rr,com);
			}
			mn=min(mn,rr);
		}
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=1;
			sub[sl+1]=i;
			dfs(dep+1,sl+1);
			sub[sl+1]=0;
			vis[i]=0;
		}
	}
	dfs(dep+1,sl);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>k;
		for (int i=1;i<n;i++)
		{
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		memset(dis,-1,sizeof(dis));
		mn=1000000000;
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++) init(i,i,-1,0);
		dfs(1,0);
		cout<<mn<<'\n';
	}
	return 0;
}



