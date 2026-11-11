#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> a,d;
ll n,m;
bool check(ll q)
{
    if(q==1)return true;
    vector<ll> pre(n+1);
    for(ll i=2;i<=q;i++)
    {
        pre[q]=pre[q]+(ll)(i-1)*d[i];
    }
    ll ans=pre[q];
    //cout <<pre[q] << " ";
    for(ll i=q+1;i<=n;i++)
    {
        pre[i]=pre[i-1]-(a[i-1]-a[i-q])+d[i]*(q-1);
        ans=min(ans,pre[i]);
        //cout <<pre[i]<< " ";
    }
    //cout <<endl;
    if(ans<=m)return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    a.resize(n+1),d.resize(n+1);
    for(ll i=1;i<=n;i++)cin >> a[i];
    stable_sort(a.begin()+1,a.end());
    for(ll i=1;i<=n;i++)
    {
        d[i]=a[i]-a[i-1];
    }
    ll l=1,r=n,ans;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans;
    return 0;
}
