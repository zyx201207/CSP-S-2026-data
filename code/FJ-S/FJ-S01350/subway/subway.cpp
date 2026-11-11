#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=500005,N=505;
int c,n,m,d,q,w[M],z,dis[N][N],x,y,ans; 
vector<pair<int,int>> s[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>z;
		for(int j=1;j<=z;j++)
		{
			cin>>x>>y;
			s[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto j:s[i])
		{
			for(auto k:s[i])
			{
				if(j.first==k.first)
				{
					continue;
				}
				dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
			}
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		ans=1e18;
		cin>>x>>y;
		for(auto j:s[x])
		{
			for(auto k:s[y])
			{
				ans=min(ans,dis[j.first][k.first]+w[x]+w[y]+j.second+k.second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//注意w不需要考虑
//注意n<=500，考虑类似floyd的O(n^3)
//以线路为点建边，两个线路之间连边当且仅当两条线可以在某个车站换乘，边权为到站厅的时间之和
//询问枚举开始的线路与结束的线路，查询两点间距离，再加上w与到站厅的距离，单次O(d^2)
//总的O(n^3+qd^2)就做完了？？？ 
//建边次数会不会炸？注意每个(线路，点)对至多建d个边，这样的对至多5e5个 
