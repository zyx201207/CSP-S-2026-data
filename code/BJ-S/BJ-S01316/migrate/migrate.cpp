#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 2e6+5;
int a[N],suf[N],nxt[N],ch[N];
int dp[N];
vector<int> g[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c,t; cin>>c>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        if(n>5000)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i = 1;i<=n;i++) cin>>a[i];
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=i-1;j++) if(a[j]+m >= a[i]) g[i].push_back(j);
        }
        int ans = 0;
        for(int k = 1;k<n;k++)
        {
            for(int i = 1;i<=n;i++) dp[i] = 2e18;
            dp[k] = 0;
            for(int i = k;i<=n;i++)
            {
                int cnt = 1;
                for(auto j:g[i])
                {
                    if(j<k) continue;
                    if(dp[i] == dp[j]+1) cnt++;
                    else if(dp[i] > dp[j]+1) dp[i] = dp[j]+1,cnt = 1;
                }
                if(cnt == 2) ans++;
            }
        }
        cout<<ans<<endl;
        for(int i = 1;i<=n;i++) g[i].clear();
    }
    return 0;
}
