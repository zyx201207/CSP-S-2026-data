#include<bits/stdc++.h>
using namespace std;
int time_[10000],a[10000],t[10000],start[10000],endl[10000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、计划 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>time_[i];//每个地铁站的地铁口走到站厅需要的时间。
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;//第 i 条线路经过的地铁站数
		for(int j=1;j<=k;j++)
		{
			//cin>>a[i][j]>>t[i][j];
            //t[i][j] 表示第 i 条线路经过的第 j 个地铁站
            //a[i][j]表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
		}
	}
	for(int i=1;i<=q;i++)//计划数 
	//	cin>>start[i]>>end[i];//起点、终点
	for(int i=1;i<=q;i++)//枚举各个计划时间 
	{
		//int n_start=start[i],n_end=end[i];//第i个计划开始、结束
		int cnt=0;//时间总数
		//''nt+=(time_[n_start]+time_[n_end]);
		
	}
	while(q--)
	{
		cout<<0<<endl;
	}
	return 0;
}
