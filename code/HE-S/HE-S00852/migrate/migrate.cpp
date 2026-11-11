#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
const int inf=1e18;
int c,T,n,d,x[N],cnt[N],dis[N]; 
vector<int> e[N];
bool vis[N];
queue<int> q;
void bfs(int s)
{
	for (int i=1;i<=n;i++) 
	{
		dis[i]=inf;
		cnt[i]=0;
	}
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	while (q.size())
	{
		int u=q.front();
		q.pop();
		for (int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if (dis[v]==dis[u]+1) cnt[v]+=cnt[u];
			else if (dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			cin >> x[i];
			e[i].clear();
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (x[j]-x[i]<=d)
				{
					e[i].push_back(j);
					e[j].push_back(i);
				}
				else break;
			}
		}
		for (int i=1;i<=n;i++)
		{
			bfs(i);
			for (int j=i+1;j<=n;j++)
			{
				if (cnt[j]==2) ans++;
			}
		} 
		cout << ans << "\n";
	} 
}
/*
n<=300 £º ÅÜ¸öBFS,O(n^3),24pts»ò40pts 
¶à²â 



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
