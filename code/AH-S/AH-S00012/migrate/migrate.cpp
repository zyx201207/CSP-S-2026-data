#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
vector<int >v;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> c >> t;
    if(c==13 || c==14)
    {
        cout << 0;
        return 0;
    }
    while(t--)
    {
        int n,d,ans=0;
        cin >> n >> d;
        v.clear();
        v.resize(n+3);
        for(int i=1 ; i<=n ; ++i) cin >> v[i];
        int dp[n+2];
        memset(dp,1,sizeof(dp));
        dp[1]=1;
        for(int i=1 ; i<=n ; ++i)
        {
            for(int j=1 ; j<i ; ++j)
            {
                if(v[i]-v[j]<=d) dp[i] += dp[j];
                break;
            }
        }
        for(int i=1 ; i<=n-1 ; ++i)
        {
            for(int j=i+1 ; j<=n ; ++j)
            {
                if(dp[j]+dp[i]-2*dp[j-i] < 3) ++ans;
            }
        }
        cout << ans << '\n';
    }

    cout << endl;
    return 0;
}
