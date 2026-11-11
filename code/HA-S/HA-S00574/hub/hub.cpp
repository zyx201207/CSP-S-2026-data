#include<bits/stdc++.h>
using namespace std;
vector<int>a[(int)1e5+5];
int vis[1005];
int siv[1005];
int f[15][1005];
int dep[1005];
int dis[1005][1005];
int res=0;	
int n,k;
void dfs(int x,int fa)
{
	for(int i:a[x])
	{
		if(i==fa||vis[i]==0||siv[i]==1)continue;
		siv[i]=1;
		dfs(i,x);
	}
}
void bfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[0][x]=fa;
	for(int j=1;j<14;j++)
	{
		f[j][x]=f[j-1][f[j-1][x]];
	}
	for(int i:a[x])
	{
		if(i==fa)continue;
		bfs(i,x);
	}
}
int lca(int x,int y)
{
	if(x==y)return x;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=13;i>=0;i--)
	{
		if(dep[f[i][x]]>=dep[y])x=f[i][x];
	}
	if(x==y)return x;
	for(int i=13;i>=0;i--)
	{
		if(f[i][x]!=f[i][y])
		{
			x=f[i][x];
			y=f[i][y];
		}
	}
	return f[0][x];
}
bool check()
{  
	for(int i=1;i<=n;i++)
	{
		siv[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>2)return 0;
		if(vis[i]&&siv[i]==0)
		{
//			cout<<"here:"<<cnt<<' '<<i<<'\n';
			siv[i]=1;
			dfs(i,0);
			cnt++;
		}
	}
	if(cnt>2)return 0;
	vector<int>s;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			s.push_back(i);	
		}
	}
	bfs(1,0);
	res=-1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int p=INT_MAX;
			for(int j:s)
			{
				int l=lca(j,i);
				int tmp=dep[i]+dep[j]-2*dep[l];
				p=min(p,tmp);
			}
			res=max(res,p);
		}
	}
//	cout<<"This is a union:\n";
//	for(int j:s)cout<<j<<' ';
//	cout<<'\n';
//	cout<<"And this is the r of the union:\n";
//	cout<<res<<'\n';
//	cout<<flush;
//	if(res==1)system("pause");
	return 1;
}
void solve()
{
	res=0;
	memset(vis,0,sizeof(vis));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if(n>15&&k==2)
	{
		bfs(1,0);
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int l=lca(i,j);
				int res=dep[i]+dep[j]-2*dep[l];
				dis[i][j]=dis[j][i]=res;
			}
		}
		int ans=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int res=0;
				for(int k=1;k<=n;k++)
				{
					if(k!=i&&k!=j)
					{
						res=max(res,min(dis[i][k],dis[j][k]));
					}
				}
				ans=min(ans,res);
			}
		}
		cout<<ans<<'\n';
		return;
	}
	int ans=INT_MAX;
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)!=k)continue;
		for(int k=1;k<=n;k++)
		{
			if(i&(1<<(k-1)))vis[k]=1;
			else vis[k]=0;
		}
		if(check())
		{
			ans=min(ans,res);
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
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
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
/*
0 1
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
