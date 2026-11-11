#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const ll N=5e5+100;
ll a[N],an[N];
ll l,r;
ll now,ans;
ll n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) an[i]=a[i]-a[i-1];
    l=1,r=1;
    while(r<=n)
    {
        now+=an[r]*(r-l);
        while(a[r]==a[r+1]) r++;
        while(now>m)
        {
            now-=a[r]-a[l];
            l++;
        } 
        ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans;
    return 0;
}