#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int road[n+1][m+1];
	for(int i = 0;i <= n;++i)
		for(int j = 0;j <= m;++j)
			road[i][j] = 1e9;
	int map[n+1][n+1];
	for(int i = 0;i <= n;++i)
	{
		for(int j = 0;j <= n;++j)
		{
			map[i][j] = 1e9;
			if(i==j)map[i][j] = 0;
		}
	}
	vector<int> w(m+1,1e9);
	for(int i = 1;i <= m;++i)
		cin>>w[i];
	for(int i = 1;i <= n;++i)
	{
		int k;
		cin>>k;
		for(int j = 1;j <= k;++j)
		{
			int v,t;
			cin>>v>>t;
			road[i][v] = t;
		}
	}
	for(int i = 1;i <= m;++i)
	{
		vector<int> temp;
		for(int j = 1;j <= n;++j)
		{
			if(road[j][i] != 1e9)
				temp.push_back(j);
		}
		for(const auto& j : temp)
		{
			for(const auto& k : temp)
			{
				map[j][k] = min(map[j][k]
				,road[j][i]+road[k][i]);
			}
		}
	}
	/**for(int i = 1;i <= n;++i)
	{
		cout<<"第"<<i<<"条线经过站点\n";
		for(int j = 1;j <= m;++j)
		{
			cout<<"\t"<<j<<"，用时"<<road[i][j]<<endl;
		}
	}**/
	while(q--)
	{
		int ans = 1e9;
		int x,y;
		cin>>x>>y;
		vector<int> e;//能够直通y的
		vector<int> s;//能够直通x的
		for(int i = 1;i <= n;++i)
		{
			if(road[i][y] < 1e9)e.push_back(i);
			if(road[i][x] < 1e9)s.push_back(i);
		}
		int fis = 0,fie = 0;
		for(auto& from : s)
		{
			for(auto& to : e)
			{
				int vis[n+1];
				for(int i = 0;i <= n;++i)
					vis[i] = 1e9;
				vis[from] = road[from][x];
				for(int i = 1;i <= n;++i)
				{
					for(int j = 1;j <= n;++j)
					{
						vis[j] = min(vis[j],
						vis[i]+map[i][j]);
					}
				}vis[to] += road[to][y];
				ans = min(ans,vis[to]);
			}
		}cout<<ans+w[x]+w[y]<<endl;
	}
}
