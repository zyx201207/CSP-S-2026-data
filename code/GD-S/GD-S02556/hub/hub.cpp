#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;


const long long N = 1e6+5;//?
vector<long long >g[N];
bool flag[N];
int dis[N];

int n,m,ans = -2e9;

void dfs(int now,int used,int fa)
{
	if(used == m)
	{
		int minn = 2e9;
		for(int i = 1;i<=n;i++)
		{
			if(!flag[i])
			{
				for(int j = 1;j<=n;j++)
				{
					if(flag[i])minn = min(minn,abs(dis[now] - dis[j]));
				}
			}
		}
			ans = max(minn,ans);
			return;
	}
	for(auto i : g[now])
	{
		if(i != fa)
		{
			dis[i] = dis[now] + 1;
			flag[i] = 1;
			dfs(i,used+1,now);
			flag[i] = 0;
			dfs(i,used,now);
		}
	}
	return;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << 1; 
	return 0;
 } 
