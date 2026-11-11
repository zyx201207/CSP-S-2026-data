#include<bits/stdc++.h>
using namespace std;
int ans; 
int w[12530];
int k[505],a[505][12530],t[505][12530];
queue<int> qq[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;//m:地铁站数，n:地铁路线数，q:出行计划数 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];//第i个地铁站地铁口到站厅时间 
	}
	for(int i=1;i<=n;i++)//第i条路线 
	{
		cin>>k[i];//第i条线经过k[i]个地铁站 
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];//a[i][j]:第i条线路经过的第j个地铁站,t[i][j]:第i条线路经过的第j个地铁站从站厅走到第i条线路的站台需要的时间
			qq[i].push(a[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+2*t[x][y]<<"\n";
	}
	return 0;
}
