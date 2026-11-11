#include<bits/stdc++.h>
using namespace std;
int n;//,dp[500050][500050],b[500050][500050];
long long m,a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int y=1;y<=n;y++)
	{
	 scanf("%lld",&a[y]);
	}	
		sort(a+1,a+n+1);
	
		if(n<=16)
		{
			long long b[n+1][n+1];
			memset(b,-1,sizeof(b));
		for(int y=0;y<=n;y++)
	{
	
		b[0][y]=0;
	    b[y][0]=0;
		
	}
			for(int y=1;y<=n;y++)
			 for(int u=1;u<=y;u++)
			 {
			 	b[y][u]=a[y]-a[u]+b[y][u-1];
			 }
		int f[n+1][n+1];
		memset(f,0,sizeof(f));
		for(int y=1;y<=n;y++)
		for(int u=1;u<=y;u++)
		{
			for(int v=u;v>=1;v--)
			{
				if(b[y][u]-b[y][v]<=m)
				f[y][u]=max(f[y][u],u-v+1);
			}
			 }
			 int ans=0;
			 for(int y=1;y<=n;y++)
			 for(int u=1;u<=y;u++)
			 ans=max(ans,f[y][u]);	 
			 cout<<ans;
		}
	else
	{
			
   long long c=a[1]-a[0];
    long long mi=m;
    int ans=1;
    for(int y=n-1;y>0;y--)
    { 
    	if(mi<c*ans)
    {
	break;}
    	else
    {mi-=c*ans;
    ans++;
		}	
	}
	cout<<ans;}
/*	memset(b,-1,sizeof(b));
	for(int y=0;y<500050;y++)
	{
	
		b[0][y]=0;
	    b[y][0]=0;
		
	}


	for(int y=1;y<=n;y++)
	for(int u=1;u<=y;u++)
	b[y][u]=b[y][u-1]+(a[y]-a[u]);
	for(int y=1;y<=n;y++)
	 for(int u=1;u<=y;u++)
	 {
	 	if(b[y][u]<=m&&b[y][u]!=-1)
	 	{
	 		dp[y][u]=max(dp[y-1][u],dp[y][u-1]+1);
		 }
        else
        dp[y][u]=max(dp[y-1][u],dp[y][u-1]);
	 }
	 cout<<dp[n][n];*/
	 return 0;
	
}
