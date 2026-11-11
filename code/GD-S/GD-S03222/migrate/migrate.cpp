#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,opx,opy,ans;
void solve()
{
    scanf("%lld%lld",&n,&d);ans=0;
    long long vis[n+5][n+5][3];memset(vis,0,sizeof vis);
    long long val[n+5];memset(val,0,sizeof val);
    for(long long i=1;i<=n;i++) scanf("%lld",&val[i]);
    for(long long i=1;i<=n;i++)
    {
    	for(long long j=i+1;j<=n;j++)
    	{
    		if((val[j]-val[i])<=d){vis[i][j][1]=1;vis[i][j][2]++;continue;}
		}
	}
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
        	if(vis[i][j][1]!=0) continue; 
            long long tmp=0x7fffffffffffffff;
            for(long long k=i+1;k<j;k++){if(vis[i][k][1]!=0&&vis[k][j][1]!=0){tmp=min(tmp,vis[i][k][1]+vis[k][j][1]);}}
            for(long long k=i+1;k<j;k++){if(vis[i][k][1]!=0&&vis[k][j][1]!=0&&(vis[i][k][1]+vis[k][j][1]==tmp)){vis[i][j][2]++;}}
            if(tmp==0x7fffffffffffffff) vis[i][j][1]=0;
            else vis[i][j][1]=tmp;
        }
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            if(vis[i][j][2]==2) ans++;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(long long i=1;i<=t;i++) solve();
    return 0;
}
