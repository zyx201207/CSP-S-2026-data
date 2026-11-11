#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
struct node{
	int v,w;
};
vector<node>v[50005];
int a[50005];
int k[50005];
vector<int>x[50005],y[50005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int xza=1,xzb=1;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		if(k[i]>2)
			xza=0;
		for(int j=1;j<=k[i];++j)
		{
			int xx=0,yy=0;
			cin>>xx>>yy;
			x[i].push_back(xx);
			y[i].push_back(yy); 
		}
		
	}
	 if(xza||(c>=7&&c<=11))
	 {	
	 	memset(dp,0x3f,sizeof(dp));
	 	for(int i=1;i<=n;++i)
	 	{
	 		
	 		//v[x[i][1]].push_back(x[i][2],y[i][2]);
			//v[x[i][2]].push_back(x[i][1],y[i][1]);
			dp[x[i][1]][x[i][0]]=y[i][0]+y[i][1];
			dp[x[i][0]][x[i][1]]=y[i][1]+y[i][0];
				
	 	}
	 	for(int i=1;i<=m;++i)
	 	{	
	 		for(int j=1;j<=m;++j)
	 			for(int k=1;k<=m;++k)
	 				if(k!=i&&i!=j&&j!=k)
	 					dp[i][k]=min(dp[i][j]+dp[j][i]+dp[k][j]+dp[j][k],dp[i][k]);
		}
			
		while(q--)
		{
			int qd,zd;
			cin>>qd>>zd;
			cout<<dp[qd][zd]+a[qd]+a[zd]<<"\n";
		}
		 
	 }	
	return 0;
}

