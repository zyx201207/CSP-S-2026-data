#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void qr(T &x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int N=5100,M=2e6+10;
int a[M],n,d;
int dis[N][N],f[N][N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int testnum,T=0;qr(testnum);qr(T);
//	testnum=11;
	if(testnum==11||testnum==12)
	{
		while(T--)
		{
			qr(n);qr(d);
			for(int i=1;i<=n;i++)qr(a[i]);
			if(n<=3){puts("0");continue;}
			int x=d/(a[2]-a[1]);
			if(x==0||x==1){puts("0");continue;}
			printf("%lld\n",max(n-(2*x-1),0ll));
		}
	}
	else
	{
		while(T--)
		{
			qr(n);qr(d);
			for(int i=1;i<=n;i++)qr(a[i]);
			if(n<=3){puts("0");continue;}
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=0x3f3f3f3f;
			for(int i=1;i<=n;i++)dis[i][i]=0;
			for(int i=1;i<=n;i++)
			{
				int nxt=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
				for(int j=i+1;j<=nxt;j++)dis[i][j]=dis[j][i]=1;
			}
			for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(i!=k)for(int j=1;j<i;j++)if(j!=k)
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=0;
			for(int i=1;i<=n;i++)f[i][i]=1;
			for(int len=2;len<=n;len++)for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				int nxt=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
				for(int k=i+1;k<=min(nxt,j);k++)
					if(dis[k][j]+1==dis[i][j])f[i][j]+=f[k][j];
			}
			long long ans=0;
			for(int i=1;i<=n;i++)for(int j=i+2;j<=n;j++)ans+=f[i][j]==2;
			printf("%lld\n",ans);
		}
	}
}
