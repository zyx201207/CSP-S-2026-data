#include<bits/stdc++.h>
using namespace std;
long long a[1005],dis[1005][1005],cnt[1005][1005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n;
        long long m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        memset(dis,0x3f,sizeof dis);
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++){
                if(abs(a[j]-a[i])<=m)
                {
                    dis[i][j]=1;
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(k>i&&k<j) dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(k>i&&k<j&&dis[i][k]+dis[k][j]==dis[i][j])
                    {
                        cnt[i][j]++;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(cnt[i][j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
