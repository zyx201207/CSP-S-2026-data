#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=5e4+5;
int w[N],a[505][N],t[505][N],id[505][N],vis[N],sum=INT_MAX;
vector<int>siz[N],q[N];
void dfs(int u,int now,int step,int e)//现在在哪 几号线 步数 终点 
{
	if(u==e)
	{
		sum=min(sum,t[now][id[now][u]]+step);
		return ;
	}
	for(int v:q[u])
	{
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=0;i<siz[v].size();i++)
		{
			if(siz[v][i]==now) dfs(v,now,step,e);
			else 
			{
				dfs(v,siz[v][i],step+t[now][id[now][u]]+t[siz[v][i]][id[siz[v][i]][u]],e);
			}
		}
	}
}
void clean(int m)
{
	for(int i=0;i<=m;i++) vis[i]=0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int gunmu;
	cin>>gunmu;
	int n,m,d,qq;
	cin>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j!=1)
			{
				q[a[i][j]].push_back(a[i][j-1]);
				q[a[i][j-1]].push_back(a[i][j]);
			}
			siz[a[i][j]].push_back(i);
			id[i][a[i][j]]=j;
		}
	}
	while(qq--)
	{
		int x,y;
		cin>>x>>y;
		int ans=INT_MAX;
		sum=INT_MAX;
		for(int i=0;i<siz[x].size();i++)
		{
			vis[x]=1;
			dfs(x,siz[x][i],0,y);
			ans=min(ans,sum+w[x]+w[y]+t[siz[x][i]][id[siz[x][i]][x]]);
			clean(m);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
