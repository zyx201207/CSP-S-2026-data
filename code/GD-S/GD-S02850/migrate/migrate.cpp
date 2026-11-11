#include<bits/stdc++.h>
using namespace std;

const int N=3e2+10;
long long d,dis[N][N],x[N];
int n,t,c,sum[N][N]; 

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) dis[i][j]=0;
				else dis[i][j]=2e18;
			}
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++) 
				if(i!=j&&x[i]-x[j]<=d) dis[i][j]=dis[j][i]=1;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++) 
				for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(dis[i][j]==i-j) continue;
				for(int k=i+1;k<j;k++)
					if(dis[i][k]+dis[k][j]==dis[i][j]) sum[i][j]++;				
			}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) if(sum[i][j]==2) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
