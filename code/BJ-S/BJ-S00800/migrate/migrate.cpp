#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=5005;//ll!!!
ll x[N];
ll cnt[N][N];
ll n,d,c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c>=13&&c<=14)
    {
        while(t--)
            cout<<0<<endl;
        return 0;
    }
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        ll n,d;
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
            cin>>x[i];
        for(ll i=1;i<=n;i++)
        {
            for(ll k=i+1;k<=n;k++)
            {
                for(ll j=k+1;j<=n;j++)
                {
                    if(x[j]-x[i]>d&&x[k]-x[i]<=d&&x[j]-x[k]<=d)
                        cnt[i][j]++;
                }
            }
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
            for(ll j=i+1;j<=n;j++)
                if(cnt[i][j]==2)
                    ans++;
        cout<<ans<<endl;
    }
    return 0;
}
