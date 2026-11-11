#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5,INF=2e18;
int C,T,n,d,ans;
int a[N],f[N],g[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>C>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int st=1;st<=n;st++)
        {
            for(int i=st;i<=n;i++) f[i]=INF,g[i]=0;
            f[st]=0;g[st]=1;
            for(int i=st+1;i<=n;i++)
            {
                for(int j=i-1;j>=st;j--)
                {
                    if(a[i]-a[j]<=d)
                    {
                        if(f[j]+1<f[i])
                        {
                            f[i]=f[j]+1;
                            g[i]=0;
                        }
                        if(f[j]+1==f[i]) g[i]+=g[j];
                    }
                    else break;
                }
            }
            for(int i=st;i<=n;i++) if(g[i]==2) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
