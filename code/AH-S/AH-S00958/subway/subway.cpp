#include <bits/stdc++.h>
using namespace std;
int check(int goal,int now){
	for(int i=1;i<=m;i++)
	{
		
	}
};
struct Node{
	bool passway[501];
	long long t[501];//t地铁站站厅走到该线路站台的时间
	long long w;//每个地铁站中从地铁口走到站厅的时间
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;//c编号 n线路数 m地铁站数 d限制数 q计划数
    long long ans=0;
    Node nodes[500001];
	
	for(int i=1;i<=m;i++)
	{
	    cin>>nodes[i].w;
	}
	
	int k[501],a[501][501];//k经过的地铁站数 a经过的地铁站
	for(int i=1;i<=n;i++)
	{
	    cin>>k[i];
	    for(int j=1;j<=k[i];j++)
	    {
		    cin>>a[i][j];
		    cin>>nodes[a[i][j]].t[i];
		    nodes[a[i][j]].passway[i]=true;
		}	
	}
	
	int x[100001],y[100001];//x起点 y终点
	for(int r=1;r<=q;r++)
	{
	    cin>>x[r]>>y[r];	
	}
	
	for(int i=1;i<=q;i++)
	{
		ans=nodes[x[i]].w+nodes[y[i]].w;
		
	}
    return 0;
}
