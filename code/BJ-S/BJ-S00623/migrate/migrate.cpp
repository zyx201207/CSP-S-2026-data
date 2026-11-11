#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[305],dp[10][10],cnt[10][10],ans;
void floyd()
{
    /*
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            for(int k = 1;k <= n;k++)
                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    cnt[i][j] = 1;
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
                else if(dp[i][j] == dp[i][k] + dp[k][j] && (k != i && k != j)) cnt[i][j]++;
    */
    for(ll len = 3;len <= n;len++)
        for(ll i = 1,j = i + len - 1;i <= n - len + 1;i++,j++)
            for(ll k = 1;k <= n;k++)
                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    cnt[i][j] = 1;
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
                else if(dp[i][j] == dp[i][k] + dp[k][j] && (k != i && k != j)) cnt[i][j]++;
}
ll mlb(ll x)
{
    ll l = 1,r = n;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(a[mid] == x) return mid;
        if(a[mid] > x) r = mid - 1;
        if(a[mid] < x) l = mid + 1;
    }
    return n;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        ans = 0;
        memset(dp,0x3f,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        cin >> n >> d;
        ll ls; cin >> a[1];ls = a[1];a[1] = 0;
        for(ll i = 2;i <= n;i++)
        {
            cin >> a[i];
            if(ls < 0) a[i] -= ls;
        }
        for(int i = 1;i <= n;i++) { dp[i][i] = 0; cnt[i][i] = 1; }
        for(int i = 1;i < n;i++)
            if(a[i + 1] - a[i] <= d)
            {
                dp[i][i + 1] = dp[i + 1][i] = a[i + 1] - a[i];
                cnt[i][i + 1] = cnt[i + 1][i] = 1;
            }

        /*
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= mlb(a[i] + d);j++)
            {
                cnt[i][j] = 1;
                dp[i][j] = j - i;
            }
        */
        floyd();
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++)
                ans += (cnt[i][j] == 2);
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
