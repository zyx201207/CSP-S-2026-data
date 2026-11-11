#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n,k;
int dis[N]; 
bool vis[N];
vector<int> v[N];
void dfs(int u,int p)
{
	vis[u]=1;
	for(auto i:v[u])
	{
		if(p&(1<<(i-1)) && !vis[i]) dfs(i,p);
	}
}
void sou(int u,int f,int w)
{
//	cout<<u<<endl;
	dis[u]=min(dis[u],w);
	for(auto i:v[u])
	{
		if(i==f) continue;
		sou(i,u,w+1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int ccc,abc;
	scanf("%d%d",&ccc,&abc);
	while(abc--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++)
		{
			int a,b;scanf("%d%d",&a,&b);
			v[a].push_back(b);v[b].push_back(a); 
		}
		int ans=(int)1e9;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0,q=0;
			for(int j=1;j<=n;j++) vis[j]=0,dis[j]=(int)1e9;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1))) q++;
				if(i&(1<<(j-1)) && !vis[j])
				{
					cnt++;
					dfs(j,i);
				}
			}
			if(q>k) continue;
			if(cnt>2) continue;
			int mx=0;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1))) sou(j,j,0);
			}
			for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
			ans=min(ans,mx);
		}
		for(int i=1;i<=n;i++) v[i].clear();
		printf("%d\n",ans);
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
