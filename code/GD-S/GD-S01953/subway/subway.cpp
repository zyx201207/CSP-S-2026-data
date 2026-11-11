#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int st,en;
int w[500010],a[500010];
struct dat
{
	int id,t;
};
vector<dat> v[500010];
int ans=1e9;
int dis[500010],vis[500010];
void dfs(int s,int sum)
{
	if(sum>ans)
	{
		return;
	}
	if(s==en)
	{
		ans=min(ans,sum);
		return ;
	}
	vis[s]=1;
	for(int i=0; i<=v[s].size(); i++)
	{
		if(dis[v[s][i].id]>sum+v[s][i].t && !vis[v[s][i].id])
		{
			dis[v[s][i].id]=sum+v[s][i].t;
			vis[v[s][i].id]=1;
			dfs(v[s][i].id,sum+v[s][i].t);
			vis[v[s][i].id]=0;
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++)
	{
		cin >> w[i];
	}
	for(int i=1; i<=n; i++)
	{
		int l;
		cin >> l;
		for(int j=1; j<=l; j++)
		{
			int t;
			cin >> a[j] >> t;
			for(int k=1; k<=i-1; k++)
			{
				v[a[k]].push_back({a[j],t});
				v[a[j]].push_back({a[k],t});
			}
		}
	}
	for(int i=1; i<=q; i++)
	{
		cin >> st >> en;
		dfs(st,0);
		cout << ans << endl;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		ans=1e9;
	}
	return 0;
}
