#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,i,j,l,a[501][501],t[501][501],w[501],k,xr,yr,cost[501][501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(cost,0x3f,sizeof(cost));
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i],cost[i][i]=0;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
			cin>>a[i][j]>>t[i][j];
		for(j=1;j<=k;j++)
			for(l=1;l<=k;l++)
				if(j!=l)
					cost[a[i][j]][a[i][l]]=cost[a[i][l]][a[i][j]]=min(cost[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
	}
	for(l=1;l<=m;l++)
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++)
				cost[i][j]=min(cost[i][j],cost[i][l]+cost[j][l]);
	while(q--)
	{
		cin>>xr>>yr;
		cout<<cost[xr][yr]+w[xr]+w[yr]<<"\n";
	}
	return 0;
}
