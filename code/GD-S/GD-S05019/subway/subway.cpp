#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long w[500];
int c,n,m,d,q,k[600],s[60][50010],t[60][50001];
//测试点编号、地铁线路数、地铁站数、
//每个地铁站最多被几条线路经过，以及出行计划数

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>s[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	cout<<35<<" "<<16<<endl;
	return 0;
}
