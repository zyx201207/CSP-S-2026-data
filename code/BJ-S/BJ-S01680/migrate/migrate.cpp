#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const ll INF=-4e18;
ll c,t,n,d,a[N],dp[N][3],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)dp[i][1] = dp[i][2] = 0;
        for(int i=1;i<=n;i++)
        {
            int pos1=upper_bound(a+1,a+n+1,a[i]+d)-a-1,pos2=upper_bound(a+1,a+n+1,(i-1<=0?INF:a[i-1])+d)-a-1,pos3=upper_bound(a+1,a+n+1,(i-2<=0?INF:a[i-2])+d)-a-1;
            ans += (max(pos2,i)-max(pos3,i))*dp[i][1]+(pos1-max(pos2,i))*dp[i][2];
            //cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<ans<<" "<<i<<endl;
            if(pos1==i)continue;
            if((a[pos1]-(i-2<=0?INF:a[i-2]))<=d)continue;
            if((a[pos1]-(i-1<=0?INF:a[i-1]))<=d)
            {
                dp[pos1][2] += dp[i][1];
                dp[pos1][1]++;
                //cout<<'a'<<d<<" "<<a[pos1]-a[i-1]<<" "<<(i-1<=0?INF:a[i-1])<<endl;
            }
            else
            {
                dp[pos1][1] += dp[i][1]+1;
                dp[pos1][2] += dp[i][2];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}