#include <bits/stdc++.h>

using namespace std;

#define int long long
#define SIZE 5005
int c,n,d;
int dis[SIZE][SIZE],path[SIZE][SIZE],x[SIZE];
bool ans[SIZE][SIZE];
vector<int> edge[SIZE];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	dis[s][s]=0;
	
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		
		for (int v:edge[u])
		{
			if (dis[s][v]==-1)
			{
				dis[s][v]=dis[s][u]+1;
				path[s][v]++;
				q.push(v);
			}
			else if (dis[s][u]+1==dis[s][v])
			{
				path[s][v]++;
				if (path[s][v]==2)
					ans[s][v]=true;
				else 
					ans[s][v]=false;
			}
		}
	}
}
signed main ()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> c >> T ;
	
	while (T--)
	{
		cin >> n >> d ;
		
		for (int i=1;i<=n;++i)
		{
			edge[i]={};
			for (int o=1;o<=n;++o)
			{
				dis[i][o]=dis[o][i]=-1;
				ans[i][o]=ans[o][i]=false;
				path[i][o]=path[o][i]=0;
			}
		}
		for (int i=1;i<=n;++i)
		{
			cin >> x[i] ;
			for (int o=1;o<i;++o)
			{
				if (x[i]-x[o]<=d)
				{
					edge[o].push_back(i);
					edge[i].push_back(o);
				}
			}
		}
		
		for (int i=1;i<=n;++i)
		{
			bfs(i) ;
		}
		
		int cnt=0;
		for (int i=1;i<=n;++i)
		{
			for (int o=i+1;o<=n;++o)
			{
				if (ans[i][o])
					cnt++;
			}
		}
		
		cout << cnt << '\n' ;
	}
	
	return 0; 
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
