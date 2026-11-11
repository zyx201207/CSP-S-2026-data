#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a,b,c,d) for(ll (a)=(b);(a)<=(c);(a)+=(d))
#define per(a,b,c,d) for(ll (a)=(b);(a)>=(c);(a)-=(d))
// #define endl '\n'

const ll MAXN=500010;

ll n,m;
ll a[MAXN], pre[MAXN];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rep(i,1,n,1) {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    rep(i,1,n,1) {
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    rep(i,1,n,1) {
        ll l=1, r=i;
        while(l<=r) {
            ll mid=(l+r)>>1;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            ll diff=a[i]*(i-mid)-(pre[i-1]-pre[mid-1]);
            if(diff<=m) {
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        ans=max(ans,(i-l+1));
    }
    cout<<ans;
    return 0;
}