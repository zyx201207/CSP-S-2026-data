#include<bits/stdc++.h>
#define ll long long
#define ri int
using namespace std;
ll c,n,m,q,g[1005][1005],dis[1005][1005],w[1005],a[1005],b[1005],x,y,z;
bool ok[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>m>>n>>c>>q;
	for(ri i=1;i<=n;i++)
	{
		cin>>w[i];
		for(ri j=0;j<=n;j++) g[i][j]=dis[i][j]=1e18;
		dis[i][0]++;
	}
	for(ri i=1;i<=m;i++)
	{
		cin>>c;
		for(ri j=1;j<=c;j++) cin>>a[j]>>b[j];
		for(ri j=1;j<=c;j++) for(ri k=j+1;k<=c;k++) g[a[j]][a[k]]=g[a[k]][a[j]]=min(g[a[j]][a[k]],b[j]+b[k]);
	}
	/*for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=n;j++) cout<<g[i][j]%10000000000ll<<" ";
		cout<<"\n";
	}*/
	while(q--)
	{
		cin>>x>>y;
		if(dis[x][y]==1e18) dis[x][y]=dis[y][x];
		if(dis[x][y]==1e18)
		{
			dis[x][x]=0;
			for(ri i=1;i<=n;i++) ok[i]=1;
			for(ri i=1;i<n;i++)
			{
				z=0;
				for(ri j=1;j<=n;j++) if(ok[j]&&dis[x][j]<dis[x][z]) z=j;
				ok[z]=0;
				for(ri j=1;j<=n;j++) if(dis[x][z]+g[z][j]<dis[x][j]) dis[x][j]=dis[x][z]+g[z][j];
			}
		}
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
