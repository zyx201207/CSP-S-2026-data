#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll val[500005],l[500005],r[500005],tg[500005];
ll c1[300005],c2[300005];
ll cnt1[500005],cnt2[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll minx=n+1,mint=n+1;
    for(ll i=n;i>=1;i--)
    {
        c2[a[i]]=c1[a[i]],c1[a[i]]=i;
        if(c2[a[i]])minx=i,mint=c2[a[i]];
        l[i]=i,r[i]=minx-1,tg[i]=mint,val[i]=1;
    }
    for(ll i=1;i<=n;i++)
    {
        cnt1[l[i]]+=val[i],cnt1[r[i]+1]-=val[i];
        val[tg[i]]+=val[i];

        cnt1[i]+=cnt1[i-1];
        cnt2[a[i]]+=cnt1[i];
    }
    for(ll i=1;i<=m;i++)cout<<cnt2[i]<<' ';
    cout<<'\n';

    return 0;
}