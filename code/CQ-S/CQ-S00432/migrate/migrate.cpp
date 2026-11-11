#include<bits/stdc++.h>
using namespace std;
namespace RST
{
    long long a[2000005];
    int f[305][305];
    long long cnt[305][305];
    void solve()
    {
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=1e9;
                cnt[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]-a[i]>d)
                {
                    break;
                }
                f[i][j]=f[j][i]=1;
                cnt[i][j]=cnt[j][i]=1;
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(f[i][k]+f[k][j]<f[i][j])
                    {
                        f[i][j]=f[i][k]+f[k][j];
                        cnt[i][j]=min(3ll,cnt[i][k]*cnt[k][j]);
                    }
                    else if(f[i][k]+f[k][j]==f[i][j])
                    {
                        cnt[i][j]+=cnt[i][k]*cnt[k][j];
                        cnt[i][j]=min(3ll,cnt[i][j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(f[i][j]<=1e9)
                {
                    if(cnt[i][j]==2)
                    {
                        ++ans;
                    }
                }
            }
        }
        cout<<ans<<"\n";
        return ;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c;
    int t=1;
    cin>>c>>t;
    while(t--)
    {
        RST::solve();
    }
    return 0;
}//g++ -o migrate.exe migrate.cpp -lm -O2 -std=c++14 -Wall -Wl,--stack=1000000000