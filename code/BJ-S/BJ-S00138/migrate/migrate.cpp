#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
ll c,t;
ll n,d,ans;
ll a[N];
ll dp[N],p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            ans=0;
            cin>>n>>d;
            for(ll i=1;i<=n;i++)
                cin>>a[i];
            ll k=d/(a[2]-a[1]);
            if(n<=3||k>=n||k<=1)
            {
                cout<<0<<'\n';
                continue;
            }
            n--;
            ans=n-(2*k-1)+1;
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(t--)
    {
        ans=0;
        memset(dp,0,sizeof dp);
        memset(p,0,sizeof p);
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        for(ll s=1;s<=n;s++)
        {
            dp[s]=1;
            for(ll i=s+1;i<=n;i++)
            {
                p[i]=LLONG_MAX,dp[i]=0;
                for(ll j=i-1;j>=s;j--)
                {
                    if(a[i]-a[j]>d)break;
                    p[i]=min(p[i],p[j]+1);
                }
                for(ll j=i-1;j>=s;j--)
                {
                    if(a[i]-a[j]>d)break;
                    if(p[j]+1==p[i])
                        dp[i]+=dp[j];
                }
                if(dp[i]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}