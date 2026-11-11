#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[2000005];
int dp[2000005];
int cnt[2000005];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        for(int j=1;j<=n;j++)
        {
            memset(dp,0x7f,sizeof(dp));
            memset(cnt,0,sizeof(cnt));
            dp[j]=0;
            cnt[j]=1;
            for(int k=j+1;k<=n;k++)
            {
                for(int m=k-1;;m--)
                {
                    if(m<j||arr[k]-arr[m]>d)break;
                    if(dp[k]>=dp[m]+1)dp[k]=dp[m]+1;
                }
                for(int m=k-1;;m--)
                {
                    if(m<j||arr[k]-arr[m]>d)break;
                    if(dp[k]==dp[m]+1)cnt[k]+=cnt[m];
                }
                if(cnt[k]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
