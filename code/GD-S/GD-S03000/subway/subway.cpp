#include<bits/stdc++.h>
using namespace std;
int n,m,k[505],d,q,t[505][505],a[505][505],w[500005],c,x,y;
long long dis[505][505];

int main()
{
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=504;i++)
		dis[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<x-y<<endl;
	}				 
	return 0;
}
