#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;;
typedef pair<ll,ll> pll;

const int N=2e6+233;
ll n,d,x[N],l[N],r[N];
ll dp[5005],cnt[5005];
inline void _main()
{
    cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>x[i];
    ll ans=0;
    for (int i=1;i<n;i++)
    {
        memset(dp,0x3f,sizeof dp);
        memset(cnt,0,sizeof cnt);
        dp[i]=0,cnt[i]=1;
        for (int j=i;j<n;j++)
        {
            for (int k=j+1;k<=n;k++)
            {
                if (abs(x[j]-x[k])<=d)
                {
                    if (dp[k]>dp[j]+1)
                        dp[k]=dp[j]+1,cnt[k]=cnt[j];
                    else if (dp[k]==dp[j]+1) cnt[k]+=cnt[j];
                }
                else break;
            }
        }
        for (int j=i+1;j<=n;j++)
            if (cnt[j]==2) ans++;
    }
    cout<<ans<<endl;
}


int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c,t;
    cin>>c>>t;
    if (c<=10)
    {
        while (t--) _main();
        return 0;
    }
    if (c<=12)
    {
        while (t--)
        {
            cin>>n>>d;
            for (int i=1;i<=n;i++) cin>>x[i];
            ll r=d/(x[2]-x[1]);
            if (r>=2) cout<<max(0ll,n-2*r+1)<<endl;
            else cout<<0<<endl;
        }
    }

    return 0;
}


