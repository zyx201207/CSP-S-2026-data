#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll maxn=2e5+5;

ll n,m,a[maxn];
bool fl[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    ll mxa=0;
    for(ll i=1;i<=n;i++) cin>>a[i];

    ll k=-1,ans=0;
    for(ll p=29;p>=0;p--)
    {
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if((a[i]&(1ll<<p)) && (k==-1||fl[i])) cnt++;
        }
        if(cnt>=m)
        {
            ans+=(1<<p);
            //cout<<p<<'\n';
            for(ll i=1;i<=n;i++)
            {
                if((!fl[i]&&k!=-1)) continue;
                if(a[i]&(1ll<<p)) fl[i]=true;
                else fl[i]=false;
            }
            k=p;
        }
    }

    cout<<ans<<'\n';

    return 0;
}
