#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int c,t;
int n,d;
int a[N];
int cnt,ans;
bool vis[N];
vector <int> v[N];
int dis[N];
int di;
void spfa(int x)
{
	memset(dis,127,sizeof dis);
	dis[x]=0;
	queue <int> q;
	vis[x]=1;
	q.push(x);
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		vis[k]=0;
		for(int i=0;i<(int)v[k].size();i++)
		{
			int u=v[k][i];
			int z=1;
			if(dis[u]>dis[k]+z)
			{
				dis[u]=dis[k]+z;
				if(!vis[u])
				{
					vis[u]=1;
					q.push(u);
				}
			}
		}
	}
}
void dfs(int x,int t,int len)
{
	if(t==x&&len==di){
		cnt++;
		return;
	}
	for(int i=0;i<(int)v[t].size();i++){
		int u=v[t][i];
		if(vis[u]) continue;
		vis[u]=1;
		dfs(x,u,len+1);
		vis[u]=0;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		vector<int> g[N];
		swap(g,v);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			for(int j=1;j<=i;j++)
			{
				int dis=abs(a[i]-a[j]);
				if(dis>d) continue;
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			
			for(int j=1;j<=i;j++)
			{
				cnt=0;
				if(i==j) continue;
				memset(vis,0,sizeof vis);
				vis[i]=1;
				spfa(i);
				di=dis[j];
				dfs(j,i,0);
				memset(vis,0,sizeof vis);
				vis[i]=1;
				if(cnt==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
