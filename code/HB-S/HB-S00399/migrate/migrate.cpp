#include <bits/stdc++.h>
using namespace std;
int cc,T;
int n,d,ans;
int x[20005];
vector <int> e[20005];
int a[5005][5005];
int b[5005][5005];
int c[5005][5005];
int book[20005];
void bfs(int s)
{
	queue <pair<int,int> > q;
	q.push({s,0});
	book[s]=1;
	a[s][s]=0;
	while(!q.empty())
	{
		int u=q.front().first;
		int t=q.front().second;
		q.pop();
		for(int i=0;i<int(e[u].size());i++)
		{
			int v=e[u][i];
			if(book[v]==0)
			{
				q.push({v,t+1});
				book[v]=1;
				a[s][v]=min(a[s][v],t+1);
			}
		}
	}
}
void dfs(int f,int u,int t)
{
	for(int i=0;i<int(e[u].size());i++)
	{
		int v=e[u][i];
		if(book[v]==0)
		{
			if(a[f][v]==t+1 && b[f][u]==0)
			{
				c[f][v]++;
				b[f][u]=1;
				//cout<<f<<" "<<u<<" " <<v<<"\n";
			}
			book[v]=1;
			dfs(f,v,t+1);
			book[v]=0;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>T;
	while(T--)
	{
		cin>>n>>d;
		if(n>=5005)
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(abs(x[i]-x[j])<=d)
				{
					e[i].push_back(j);
					e[j].push_back(i);
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			memset(book,0,sizeof(book));
			bfs(i);
		}
		for(int i=1;i<=n;i++)
		{
			memset(book,0,sizeof(book));
			memset(b,0,sizeof(b));
			dfs(i,i,0);
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<a[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<c[i][j]<<" ";
			cout<<"\n";
		}*/
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(c[i][j]==2)
					ans++;
		cout<<ans/2<<"\n";
	}
	return 0;
}
