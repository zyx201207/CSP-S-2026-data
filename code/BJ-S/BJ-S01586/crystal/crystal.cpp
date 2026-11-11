#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005
ll n,m,a[N],d[N],sumd[N];
bool cmp(ll xx,ll yy)
{
    return xx<yy;
}
bool ok(ll cntk)
{
    ll sum=0;
    for(ll i=1;i<=cntk;i++)
    {
        sum+=d[i]*(i-1);
    }
    if(sum<=m)return 1;
    for(ll i=2;i+cntk-1<=n;i++)
    {

        sum-=sumd[i+cntk-1]-sumd[i-1];
        sum+=d[i+cntk-1]*(cntk-1);
        if(sum<=m)return 1;
    }
    return 0;
}
void solve()
{
    for(ll i=1;i<=n;i++)
    {
        d[i]=a[i]-a[i-1];
        sumd[i]=sumd[i-1]+d[i];
    }
    ll l=1,r=n;
    ll cnt;
    while(l<r)
    {
        cnt=(l+r)/2;
        if(ok(cnt))l=cnt;
        else r=cnt-1;
    }
    cout<<cnt-1<<endl;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    solve();
    return 0;
}
