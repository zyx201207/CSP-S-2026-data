#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,M=305;
int c,t,n,d,a[N],f[N][2],g[N][2],p[N],ans;
inline int read()
{
	int s=0,f=1;char ai=getchar();
	while(ai<'0'||ai>'9') 
	{
		if(ai=='-') f=-1;
		ai=getchar();
	}
	while(ai>='0'&&ai<='9') s=s*10+ai-'0',ai=getchar();
	return s*f;
}
int dp[M][M][2];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		n=read(),d=read();
		if(n<=300)
		{
			for(int i=1;i<=n;i++) a[i]=read();
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dp[i][j][0]=0x3f3f3f3f3f3f3f3f,dp[i][j][1]=0;
			for(int i=2;i<=n;i++)
			{
				for(int j=i-1;j>=1&&a[i]-a[j]<=d;j--)
				{
					dp[j][i][0]=dp[j][i][1]=1;
					for(int k=j-1;k>=1;k--)
					{
//						cout<<i<<' '<<j<<' '<<k<<' '<<dp[k][i][0]<<endl;
						if(dp[k][j][0]+1<dp[k][i][0]) dp[k][i][0]=dp[k][j][0]+1,dp[k][i][1]=dp[k][j][1];
						else if(dp[k][j][0]+1==dp[k][i][0]) dp[k][i][1]+=dp[k][j][1];
					}
				}
			}ans=0;
			for(int i=1;i<=n;i++) for(int j=1;j<i;j++) if(dp[j][i][1]==2) ans++;
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n+1;i++) f[i][0]=f[i][1]=g[i][0]=g[i][1]=p[i]=0;
		for(int i=1;i<=n;i++) a[i]=read();
		f[1][0]=g[1][0]=1,ans=0;
		int U=upper_bound(a+1,a+n+1,a[1]+d)-a-1;
		if(U!=1) p[U]+=f[1][0];//,cout<<U<<' '<<f[1][0]<<endl;
		for(int i=2;i<=n;i++)
		{
//			cout<<a[i]-a[i-1]<<endl;
			int u=lower_bound(a+1,a+n+1,a[i]-d)-a,w=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
//			if(w==6) cout<<i<<endl;
			if(u!=i-1) f[i][1]=p[u+1];//,cout<<u<<' '<<p[u+1]<<endl;
			if(u!=i) 
			{
				f[i][0]+=g[u][0],f[i][1]+=g[u][1];if(a[i+1]-a[u]>d) g[i][0]+=g[u][0],g[i][1]+=g[u][1];
				if(a[i+1]-a[u]>d) p[w]+=g[u][0];
//				if(a[w-1]-a[u]>d&&w==6) cout<<"add1:"<<' '<<u<<endl; 
				f[i][0]+=i-u-1;	
				int v=min(i-1,lower_bound(a+1,a+n+1,a[i+1]-d)-a-1);
				g[i][0]+=max(0ll,v-u),p[w]+=max(0ll,v-u); 
//				for(int j=u+1;j<i;j++) 
//				{
//					f[i][0]++;
//					if(a[i+1]-a[j]>d) g[i][0]++;
//					if(a[i+1]-a[j]>d) p[w]++;
////					if(w==6) cout<<"add2:"<<' '<<j<<endl; 
//				}
			}
//			if(i>=4&&a[i]-a[i-3]>d&&a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d) 
//			{
//				cout<<i<<endl;
//				f[i][1]+=g[i-3][0];
//				if(a[i+1]-a[i-1]>d) g[i][1]+=g[i-3][0];
//			}
			f[i][0]++,g[i][0]++,p[w]++,ans+=f[i][1];
			
			//if(u!=i) p[u]+=f[i][0];//,cout<<u<<' '<<f[i][0]<<endl;
//			cout<<i<<' '<<"f:"<<f[i][0]<<' '<<f[i][1]<<' '<<"g:"<<g[i][0]<<' '<<g[i][1]<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000

0 1
4 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 1000000000000000000

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
