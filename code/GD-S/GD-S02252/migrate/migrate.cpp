#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+5;

int n,d;
int x[MAXN];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			queue<pair<int,int>>q;
			int ret[MAXN][MAXN];
			memset(ret,0,sizeof(ret));
			q.push({i,0});
			ret[i][0] = 0;
			while(!q.empty())
			{
				int u = q.front().first;
				int dis = q.front().second;
				q.pop();
				for(int v = u+1;v <= n && x[v] - x[u] <= d && dis + 1 <= n;v++)
				{
					q.push({v,dis+1});
					ret[v][dis+1]++;
				}
				for(int v = u-1;v >= 1 && x[u] - x[v] <= d && dis + 1 <= n;v++)
				{
					q.push({v,dis+1});
					ret[v][dis+1]++;
				}
			}
			
			for(int j = 1;j <= n;j++)
			{
				for(int d = 1;d <= n;d++)
				{
					if(ret[i][d] == 2)
					{
						ans++;
						break;
					}else if(ret[i][d] != 0) break;
				}
			}
		}
		cout << ans <<'\n';
	}
	return 0;
}
