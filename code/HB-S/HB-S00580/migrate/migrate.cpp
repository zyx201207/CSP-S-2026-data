#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000010],ans=0,f[5010][5010],cnt[5010][5010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i<j&&x[j]-x[i]<=d) f[i][j]=1;
                else f[i][j]=1e18;
                cnt[i][j]=1;
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(k<=i||k>=j) continue;
                    if(f[i][j]>f[i][k]+f[k][j])
                    {
                        cnt[i][j]=1;
                        f[i][j]=f[i][k]+f[k][j];
                    }
                    else if(f[i][j]==(f[i][k]+f[k][j])) cnt[i][j]++;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(cnt[j][i]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}