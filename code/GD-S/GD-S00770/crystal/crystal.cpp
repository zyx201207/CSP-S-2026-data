#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0;
ll a[500005];
bool query(ll s,ll t)
{
    return ((t-s)*(a[t]-a[t-1])-a[t-1]+a[s-1])<=m;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++)a[i]+=a[i-1];
    ll l=1;
    for(ll i=1;i<=n;i++)
    {
        while(!query(l,i))l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;

    return 0;
}
/*
1 2 4 8 9
1 3 7 15 24
*/