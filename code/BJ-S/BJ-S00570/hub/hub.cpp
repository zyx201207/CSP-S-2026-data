#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int U[N],V[N],fa[N],dis[N];
bool st[N];
vector<int> e[N];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	int u=find(x),v=find(y);
	if(u!=v) fa[u]=v;
}
queue<int> q;
void bfs()
{
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])
		{
			if(dis[v]==-1) 
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++) 
		{
			cin>>U[i]>>V[i];
			e[U[i]].push_back(V[i]);
			e[V[i]].push_back(U[i]);
		}
		int ans=2e9;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if((i>>j)&1) cnt++;
			}
			if(cnt==k)
			{
				for(int j=0;j<n;j++)
				{
					if((i>>j)&1) st[j+1]=1;
					else st[j+1]=0;
					fa[j+1]=j+1;
				}
				for(int j=1;j<n;j++)
				{
					if(st[U[j]] && st[V[j]]) merge(U[j],V[j]);
				}
				cnt=0;
				for(int j=1;j<=n;j++)
				{
					if(find(j)==j) cnt++;
				}
				if(cnt==n-k+2 || cnt==n-k+1)
				{
					for(int j=1;j<=n;j++)
					{
						if(st[j]) dis[j]=0,q.push(j);
						else dis[j]=-1;
					}
					bfs();
					cnt=0;
					for(int j=1;j<=n;j++) cnt=max(cnt,dis[j]);
					ans=min(ans,cnt);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
