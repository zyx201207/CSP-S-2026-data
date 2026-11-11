#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5,M=505,inf=(int)4e18+5;
bool flg[M];
int e[M][M],dis[M][M];
priority_queue<pii,vector<pii>,greater<pii>>hp;
void dijkstra(int n,int st)
{
	for(int i=1;i<=n;i++)dis[st][i]=inf,flg[i]=false;
	dis[st][st]=0,hp.push({0,st});
	for(;!hp.empty();)
	{
		int u=hp.top().second,dist=hp.top().first;
		hp.pop();
		if(flg[u])continue;
		flg[u]=true;
		for(int v=1;v<=n;v++)
		{
			int tmp=dist+e[u][v];
			if(tmp<dis[st][v])dis[st][v]=tmp,hp.push({tmp,v});
		}
	}
}
int w[N];
vector<pair<int,int>>arr[N];
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,a,b;j<=k;j++)cin>>a>>b,arr[a].emplace_back(i,b);
		for(int j=1;j<=n;j++)e[i][j]=inf;
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	for(int j=0;j<arr[i].size()-1;j++)
	for(int k=j+1;k<arr[i].size();k++)
	{
		int u=arr[i][j].first,v=arr[i][k].first;
		e[u][v]=e[v][u]=min(e[u][v],arr[i][j].second+arr[i][k].second);
	}
	for(int i=1;i<=n;i++)dijkstra(n,i);
	for(int a,b;q;q--)
	{
		cin>>a>>b;
		int ans=inf;
		for(int i=0;i<arr[a].size();i++)
		for(int j=0;j<arr[b].size();j++)
		{
//			cout<<arr[a][i].first<<' '<<arr[b][j].first<<':';
//			cout<<arr[a][i].second<<'+'<<dis[arr[a][i].first][arr[b][j].first]<<'+'<<arr[b][j].second<<'\n';
			ans=min(ans,arr[a][i].second+dis[arr[a][i].first][arr[b][j].first]+arr[b][j].second);
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}
/*
16:01 done
*/