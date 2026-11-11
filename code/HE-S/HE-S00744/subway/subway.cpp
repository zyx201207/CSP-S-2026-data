#include<bits/stdc++.h>
using namespace std;
//分别表示测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int c,n,m,d,q;
int w[500005];
int x[100005],y[100005];
int ii[505];
int a[1005],t[1005];
int sum[1005],top;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>ii[i];
		for(int j = 1;j<=ii[i];j++)
		{
			cin>>a[j];
		}
		for(int k = 1;k<=ii[i];k++)
		{
			cin>>t[k];
			sum[top]+=t[k];
			top++;
		}
	} 
	for(int i = 1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i = 1;i<=top-1;i++)
	{
		cout<<w[x[i]]+w[y[i]]+sum[i]<<endl;
	}
	return 0;
}
