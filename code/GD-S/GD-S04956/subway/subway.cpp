#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	//c=测试点编号
	//n=地铁线路数
	//m=地铁站数
	//d=每个地铁站最多被几条线路经过
	//q=出行计划数
	cin>>c>>n>>m>>d>>q;
	long long w[m+1]={0};
	//w[m]=从每个地铁站的地铁口走到站厅需要的时间。 
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	return 0;
}
