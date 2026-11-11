#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5005],c,t,ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
    {
        int n,d;
        ans=0;
        cin>>n>>d;
        int dis[5005][5005]={0};
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    dis[i][j]=abs(a[i]-a[j]);
                }
                else
                    dis[i][j]=0;
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j && i!=k && j!=k &&  dis[i][j]<=dis[i][k]+dis[k][j])
                    {
                        if(dis[i][j]==dis[i][k]+dis[k][j] && dis[i][j]<=d) ans++;
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}
