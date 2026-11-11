#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
vl a;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,i,j;
    cin>>n>>m;
    a.resize(n+1);
    bool fl=1;
    ll mx=-1e18;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i) fl=0;
        mx=max(mx,a[i]);
    }
    if(n==1)
    {
        cout<<1<<'\n';
        return 0;
    }
    ll ans=1;
    if(fl)
    {
        for(i=2;i<=n;i++)
        {
            ll x=(1+i-1)*(i-1)/2;
            if(x<=m)
            {
                ans=max(ans,i);
            }
            else
            {
                break;
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    fl=1;
    ll x=a[2]-a[1];
    for(i=2;i<n;i++)
    {
        if(a[i+1]-a[i]!=x)
        {
            fl=0;
        }
    }
    if(fl)
    {
        for(i=2;i<=n;i++)
        {
            ll b=(x+(i-1)*x)*(i-1)/2;
            if(b<=m)
            {
                ans=max(ans,i);
            }
            else break;
        }
        cout<<ans<<'\n';
        return 0;
    }
    sort(a.begin()+1,a.end());

    for(i=1;i<=n;i++)
    {
        ll js=0;
        ll cnt=1;
        for(j=i-1;j>=1;j--)
        {
            if(js+a[i]-a[j]<=m)
            {
                js+=a[i]-a[j];
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
5 4
1 3 4 6 7
*/