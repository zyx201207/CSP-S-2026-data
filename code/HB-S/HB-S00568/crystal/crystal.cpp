#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,mx;
ll a[N],sum[N];
bool check_p(pair<ll,ll> x){
    ll ned=x.first,pos=x.second;
    if(sum[pos]-sum[pos-ned]+m>=a[pos]*ned)
        return 1;
    else
        return 0;
}
bool check_n(ll x){
    ll mx_t=0;
    for(int i=x;i<=n;i++){
        if(check_p({x,i})){
            mx_t=max(mx_t,x);
            break;
        }
    }
    if(mx_t>=x)
        return 1;
    else
        return 0;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll l=1,r=n;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check_n(mid)){
            l=mid+1;
            mx=max(mx,mid);
        }
        else
            r=mid-1;
    }
    cout<<mx<<'\n';
    return 0;
}