#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ll a[100];

    ll c,t;cin>>c>>t;
    for(ll t1=1;t1<=t;t1++)
    {
        ll n,k;cin>>n>>k;
        for(ll i=1;i<=n;i++)
        {
            ll u,v;cin>>u>>v;
        }
        cout<<a[t1]%(n-1-k);
    }

    return 0;
}
