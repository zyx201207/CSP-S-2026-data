#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4005;
int n,k,C,T,book[N],cnt,dis[N][N],ans;
vector<int> e[N];
void dfs(int x,int f)
{
	if(!book[f]&&book[x])
	{
		cnt++;
	}
	for(int y:e[x])
	{
		if(y==f) continue;
		dfs(y,x);
	}
}
int popcnt(int x)
{
	int cnt=0;
	while(x)
	{
		x-=x&(-x);
		cnt++;
	}
	return cnt;
}
void solve()
{
	ans=1e9;
	for(int i=1;i<=n;++i) e[i].clear();
	cin>>n>>k;
	for(int x=1;x<=n;++x)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dis[i][j]=1e9;
			}
		}
	}
	for(int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
		dis[x][y]=dis[y][x]=1;
	}
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int x=1;x<=n;++x)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dis[i][j]=min(dis[i][j],dis[i][x]+dis[x][j]);
			}
		}
	}
	for(int i=1;i<(1<<n);++i)
	{
		for(int j=1;j<=n;++j)
		{
			book[j]=(i>>(j-1))&1;
		}
		cnt=0;dfs(1,0);
		if(cnt<=2&&popcnt(i)<=k)
		{
			int tmp=0;
			for(int j=1;j<=n;++j)
			{
				int dist=1e9;
				for(int x=1;x<=n;++x)
				{
					if(book[x])
					{
						dist=min(dist,dis[j][x]);
					}
				}
				// if(dist==1e9&&i==384) cout<<dis[1][8]<<' ';
				tmp=max(tmp,dist);
			}
			// cout<<tmp<<'\n';
			// if(i==384) cout<<j<<
			ans=min(tmp,ans);
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(cin>>C>>T;T;--T) solve();
	return 0;
}