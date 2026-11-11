#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll x,sum;
ll a[500005];
ll ans,anss;
ll j;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        sum+=(i-1-j+1)*(a[i]-a[i-1]);
        ans++;
        if(sum>m){
            anss=max(anss,ans-1);
            while(sum>m){
                ans--;
                j++;
                sum-=(a[i]-a[j]);
            }
        }
    }
    cout<<max(anss,ans)<<'\n';
    return 0;
}
