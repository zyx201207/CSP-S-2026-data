//没有站内换乘的地铁站吗？那很能规划了
//没有脱网运营吗？致敬最不爱超前规划的政府
#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000ll
using namespace std;
int n,m,d,q;
vector<int>w;
vector<vector<int>/*防 CE 措施*/>dis;
vector<vector<pair<int,int>/*防 CE 措施*/>/*防 CE 措施*/>lines;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ifstream cin("subway.in",ios::in);
//	ofstream cout("subway.out",ios::out);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//我正在观察图的结构，并且寻找合适的复杂度以应对 q=10^5 的询问规模。
	int tc;
	cin>>tc>>n>>m>>d>>q;
	//已经找到了一个最坏 O(md^2+n^3+qd^2) 的算法，核心是围绕线路建图，正在编写代码和样例对拍。
	w.resize(m+1,0);
	dis.resize(n+1,vector<int>(n+1,inf));
	lines.resize(m+1);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1,a,t;j<=k;j++)
			cin>>a>>t,
			lines[a].push_back(make_pair(i,t));
	}
	for(int i=1;i<=m;i++)
	{
		int len=(int)lines[i].size();
		for(int x=0;x<len-1;x++)
			for(int y=x+1;y<len;y++)
			{
				int u=lines[i][x].first,v=lines[i][y].first;
				int dist=lines[i][x].second+lines[i][y].second;
				if(dis[u][v]>dist) dis[u][v]=dis[v][u]=dist;
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		assert(x>=1&&x<=m);
		assert(y>=1&&y<=m);
		int res=inf;
		for(auto it:lines[x])
			for(auto jt:lines[y])
				res=min(res,w[x]+w[y]+it.second+jt.second+dis[it.first][jt.first]);
		cout<<res<<'\n';
	}
	//代码已通过样例和大数据的对拍，其中 subway6 这组样例的特殊性质与实现无关，运行时间大约为 500ms，因此可以初步认为通过。
	//我正在编写压力测试，以便观察程序在极限情况下的用时。
	//程序已完成，并通过与一组压力测试的对拍，复杂度为 O(md^2+n^3+qd^2)，且通常跑不满。
	//15: 44 [] Like [] Copy
	return 0;
}
