#include<bits/stdc++.h>
#define N 2000010
#define M 5010
#define int long long
using namespace std;
int n,k,a[N],d[M][M],dp[M][M];
int is(int l,int r)
{
    for(int i=l+1;i<=r;i++) if(a[i]-a[i-1]>k) return 0;
    return 1;
}
void solve()
{
    int ans=0; cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=0,d[i][j]=0;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(is(i,j))
    {
        int l=i; d[i][j]=0;
        while(l<j)
        {
            int sum=0;
            while(l<j&&(sum+a[l+1]-a[l])<=k) sum+=(a[l+1]-a[l]),l++;
            d[i][j]++;
        }
    }

    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(d[i][j]<=k) dp[i][j]=1;
    for(int len=3;len<=n;len++) for(int j=1;j+len-1<=n;j++) if(is(j,j+len-1))
    {
        int l=j,r=j+len-1,sum=0;
        for(int i=l+1;i<r;i++) if(d[l][i]+d[i][r]==d[l][r]) sum+=(dp[l][i]*dp[i][r]);
        dp[l][r]=max(dp[l][r],sum);
    }
    /*cout<<"pt::\n";
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) cout<<i<<":"<<j<<" "<<dp[i][j]<<"\n";*/
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(dp[i][j]==2) ans++;
    cout<<ans<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t; cin>>c>>t;
    while(t--) solve();
    return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
