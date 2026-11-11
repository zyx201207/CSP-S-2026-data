#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> f[500005];
map<int,int> t[520];
int dis[510][510],c,n,m,d,q,w[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;
			cin>>a;
			cin>>t[i][a];
			f[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int x:f[i])
		{
			for(int y:f[i])
			{
				if(x!=y)
				{
					dis[x][y]=min(dis[x][y],t[x][i]+t[y][i]);
					dis[y][x]=min(dis[y][x],t[x][i]+t[y][i]);
				}
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
		int x,y,minn=LONG_LONG_MAX;
		cin>>x>>y;
		for(int xx:f[x])
		{
			for(int yy:f[y])
			{     
				minn=min(minn,dis[xx][yy]+t[xx][x]+t[yy][y]);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}
