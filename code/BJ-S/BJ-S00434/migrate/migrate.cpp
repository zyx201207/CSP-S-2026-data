#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=20010;
ll c,t,n,d;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
        {
            ll x[N],dp[N],sd[N],ans=0;
            bool vis[N];
            cin>>n>>d;
            for (int i=1;i<=n;i++) cin>>x[i],vis[x[i]]=1;
            ll sub=x[2]-x[1];
            if(sub>=d || sub==0) cout<<0<<endl;
            else
            {
                ll cnt=int(d/sub);
                for (int i=1;i<=n;i++) dp[i]=i-1;
                for (int i=cnt+1;i<=n;i++)
                {
                    if(vis[x[i]-d]) dp[i]=min(dp[i],dp[i-d/sub]+1);
                }
                for (int i=cnt+1;i<=n;i++)
                {
                    if(dp[i]==2) ans++;
                    //cout<<dp[i]<<" ";
                }
                cout<<ans<<endl;
            }
        }

    return 0;
}
