#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll CF,T;
ll n,m,a[2000005],la[2000005],dp[5005],ed[5005],le[5005],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>CF>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1,j=1;i<=n;i++)
        {
            while(j<=i)
            {
                if(a[i]-a[j]<=m)
                {
                    la[i]=j;
                    break;
                }
                j++;
            }
        }
        if(n<=5000)
        {
            ans=0;
            for(int i=1;i<=n;i++)
            {
                dp[i]=1;
                dp[i-1]=0;
                le[i]=0;
                ed[0]=i;
                for(int j=i+1;j<=n;j++)
                {
                    if(la[j]==j)
                    {
                        dp[j]=dp[j-1];
                        continue;
                    }
                    ed[j]=0;
                    ll l=max(la[j],1ll*i);
                    dp[j]=dp[ed[le[l]]]-dp[l-1];
                    le[j]=le[l]+1;
                    ans+=(dp[j]==2);
                    ed[le[j]]=j;
                    dp[j]+=dp[j-1];
                }
            }
            cout<<ans<<endl;
            continue;
        }
        if(CF>=11&&CF<=12)
        {
            ll tmp=n-la[n];
            if(tmp<=1)cout<<0<<endl;
            else cout<<max(0ll,n-2*tmp+1)<<endl;
            continue;
        }
    }
    return 0;
}
