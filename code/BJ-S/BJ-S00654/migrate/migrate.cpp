#include <bits/stdc++.h>
using namespace std;
long long T,c,n,m,a[5005],f[5005],sum[5005],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int k=1;k<=n;k++)
        {
            memset(sum,0,sizeof(sum));
            memset(f,0x3f,sizeof(f));
            f[k]=1;
            for(int i=k;i<=n;i++)
            {
                for(int j=i+1;j<=n && a[j]-a[i]<=m;j++)
                {
                    if(f[i]+1>f[j])continue;
                    else if(f[i]+1<f[j])
                    {
                        sum[j]=1;
                        f[j]=f[i]+1;
                    }
                    else
                    {
                        sum[j]++;
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(sum[i]==2)ans++;
            }
        }
        cout<<ans;

    }
    return 0;
}
