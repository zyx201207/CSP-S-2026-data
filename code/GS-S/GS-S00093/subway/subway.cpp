#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,q,q1,k,w[1005];
	int d[1005][1005];
	cin>>c>>n>>m>>q>>q1;
	for(int i=1;i<=m;i++)
	{
		d[i][i]=0;
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int a1,a2,t1,t2;
		cin>>k;
	for(int j=1;j<=k;j++)
	{
		cin>>a1>>a2>>t1>>t2;
		d[a1][a2]=t1+t2;
	}
}
	for(k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<d[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
