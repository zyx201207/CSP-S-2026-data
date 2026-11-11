#include<bits/stdc++.h>
using namespace std;
int w[500100],t[500100][600],dist[600][600],x[600],y[600];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
	cin>>w[i];	
	dist[i][i]=0x3f3f; 
	}
	
	for(int i=1;i<=m;i++)
	for(int j=i+1;j<=m;j++)
	{
		dist[i][j]=dist[j][i]=0x3f3f;
	}

	for(int i=1;i<=n;i++)
	{
		int hjr;
		cin>>hjr;
		for(int j=1;j<=hjr;j++)
		{
			int c,d;
			cin>>c>>d;
			x[j]=c;
			y[j]=d;
			t[i][x[j]]=y[j];
		}
		for(int j=1;j<=hjr-1;j++)
		{
			for(int k=j+1;k<=hjr;k++)
			{
				dist[x[j]][x[k]]=min(dist[x[j]][x[k]],t[i][x[j]]+t[i][x[k]]);
				dist[x[k]][x[j]]=dist[x[j]][x[k]];	
			}	
		}
	}
	while(q--)
	{
		int ans=0;
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(dist[i][k]!=0x3f3f && dist[k][j]!=0x3f3f)
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
		cout<<ans+dist[x][y]<<endl;
	}
}
