#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dis[1010][1010],w[1010],a[1010],t[1010];
bool vis[1010];
typedef pair<int,long long> pii;
vector<vector<pii>>e;
void dij(int s)
{
	priority_queue<pii,vector<pii>,greater<pii>>qq;
	memset(vis,0,sizeof(vis));
	memset(dis[s],0x3f,sizeof(dis[s]));
	qq.push({0,s});dis[s][s]=0;
	while(qq.size())
	{
		int x=qq.top().second;qq.pop();
		if(vis[x])continue;
//		cout<<dis[s][x]<<endl;
		vis[x]=1;
		for(auto tt:e[x])
		{
			if(dis[s][tt.first]>dis[s][x]+tt.second)
			{
				dis[s][tt.first]=dis[s][x]+tt.second;
				qq.push({dis[s][tt.first],tt.first});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	e.resize(m+1);//i forget it!
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int ttt=1;ttt<=n;ttt++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i]>>t[i];
			for(int j=1;j<i;j++)
			{
				e[a[i]].push_back({a[j],t[i]+t[j]});//not e[i].push_back({j,t[i]+t[j]});!!!
				e[a[j]].push_back({a[i],t[i]+t[j]});
			}
		}
	}
	for(int i=1;i<=m;i++)dij(i);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
//		for(x=1;x<=m;x++)
//		for(y=1;y<=m;y++)
		cout<<w[x]+w[y]+dis[x][y]<<endl;
	}
}
//have no - value , so dij n * n log n is good 
//15:22 read problem error (no!!! (walk time least
//16:25 so difficult it is that i cant solve it
//16:50  is 1~11 OK(44pts)
//? is OK 
