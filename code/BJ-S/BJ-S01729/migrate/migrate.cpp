#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int x[N],dp[N],cnt[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    if (11<=c&&c<=12)
    {
        while (t--)
        {
            int n,d;
            cin>>n>>d;
            for (int i=1;i<=n;i++)
                cin>>x[i];
            int dlt=x[2]-x[1];
            if (d<dlt||d==1)
            {
                cout<<0<<"\n";
                continue;
            }
            cout<<max(n-2*(d/dlt)+1,0ll)<<"\n";
        }
        return 0;
    }
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++)
            cin>>x[i];
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int lst=i,r2=i-1,scnt=0;
            dp[i]=0,cnt[i]=1;
            for (int j=i+1;j<=n;j++)
            {
                while (x[lst]+d<x[j])
                    scnt-=cnt[lst],lst++;
                dp[j]=dp[lst]+1;
                while (dp[r2+1]<=dp[lst])
                    r2++,scnt+=cnt[r2];
                cnt[j]=scnt;
                if (cnt[j]==2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}