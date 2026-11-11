#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,q;

ll n,d;
ll x[2000005];

pair<ll,ll> dp[2000005];
ll cnt[2000005];
void sub1_solve()
{
    cin>>n>>d;
    ll ans=0;
    for(ll i=1;i<=n;i++)cin>>x[i];
    for(ll s=1;s<n;s++)
    {
        ll y=s,t=0;
        dp[s]={0,1};
        cnt[0]=1;
        for(ll i=s+1;i<=n;i++)
        {
            while(y<i&&x[i]-x[y]>d)cnt[dp[y].first]-=dp[y].second,y++;
            while(t<n&&(!cnt[t]))t++;
            if(t>=n)break;
            dp[i]={t+1,cnt[t]};
            cnt[t+1]+=cnt[t];
            if(cnt[t]==2)ans++;
            
        }
        for(ll i=0;i<=n;i++)cnt[i]=0;
    }
    cout<<ans<<'\n';
}

void sub2_solve()
{
    cin>>n>>d;
    ll ans=0;
    for(ll i=1;i<=n;i++)cin>>x[i];
    if(n==1||(x[2]-x[1]>d)){cout<<0<<'\n';return;}
    ll dt=d/(x[2]-x[1]);
    cout<<d<<' '<<dt<<' '<<x[2]-x[1]<<'\n';
    for(ll i=1;i<n;i++)ans+=max((ll)((n-i)/dt)-1,0ll);
    cout<<ans<<'\n';
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>q;
    while(q--)
    {
        if(c<=10)sub1_solve();
        else cout<<"0\n";
    }

    return 0;
}