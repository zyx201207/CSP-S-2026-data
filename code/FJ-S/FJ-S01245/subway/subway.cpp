#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int c,n,m,d,q;
//c:测试点编号 
//n:地铁线路数
//m:地铁站数
//d:每个地铁站最多被几条线路经过
//q:出行计划数。
long long w[500005];
long long dt[5005];
long long zt[5005];
long long f[5005][5005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=1e12;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>dt[j]>>zt[j];
			for(int p=1;p<j;p++)
			{
				long long sj=zt[p]+zt[j];
				f[dt[p]][dt[j]]=f[dt[j]][dt[p]]=min(f[dt[p]][dt[j]],sj);
			}
		}
	}
	for(int p=1;p<=m;p++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(i!=j)
					f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=f[x][y]+w[x]+w[y];
		if(x==y)ans=0;
		cout<<ans<<'\n';
	}
	return 0;
}


