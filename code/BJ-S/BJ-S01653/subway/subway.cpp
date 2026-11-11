#include<bits/stdc++.h>
using namespace std;
struct node
{
	int xl,z;
};
int x,y;
int ans=2e9;
int w[500010];//地铁口走到站厅的时间
int k[500010];//表示第 i 条线路经过的地铁站数
int a[510][500010];//a[i][j]:表示第 i 条线路经过的第 j 个地铁站
int t[510][500010];//t[i][j]:表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
bool vis[500010];
vector<node>l[500010];
void dfs(int s,int sum,int nx)
{
	if(sum>ans)
	{
		return ;
	}
	for(auto it:l[y])
	{
		if(s==it.xl&&nx==it.z)
		{
			ans=min(ans,sum);
			return ;
		}
	}
	for(auto it:l[a[nx][s]])
	{
		if(vis[a[it.xl][it.z+1]]==0)
		{
			dfs(it.z+1,sum+t[it.xl][it.z+1],it.xl);
			vis[a[it.xl][it.z+1]]=1;
		}
		if(vis[a[it.xl][it.z-1]]==0)
		{
			dfs(it.z-1,sum+t[it.xl][it.z-1],it.xl);
			vis[a[it.xl][it.z-1]]=1;
		}
	}
}
int main()
{
	//please give me AC
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			l[a[i][j]].push_back({i,j});
		}
	}
	while(cin>>x>>y)
	{
		ans=2e9;
		memset(vis,0,sizeof(vis));
		for(auto is:l[x])
		{
			dfs(is.z,w[x]+w[y],is.xl);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
