#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, m, ans = 0;
vector<ll> a, suf;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    a.assign(n+1, 0);
    suf.assign(n+2, 0);
    bool sp = true;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }ll k = a[2]-a[1];
    for(int i = 3;i<=n;i++){
        if(a[i]-a[i-1]!=k) sp = false;
    }if(sp){
        for(int i = 1;i<=n;i++){
            ll l = 1, r = i, ansnow = i;
            while(l<=r){
                ll mid = (r+l)>>1;
                if(a[i]*(i-mid+1)-(a[i]+a[mid])*(i-mid+1)/2<=m){
                    ansnow = mid;r = mid-1;
                    //cout<<i*(i-mid+1)-(i+mid)*(i-mid+1)/2<<endl;
                }else l = mid+1;
            }ans = max(ans, i-ansnow+1);
        }cout<<ans<<endl;
    }
    sort(a.begin()+1, a.end());
    for(int i = n;i>=1;i--){
        suf[i] = suf[i+1]+a[i];
    }
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=i;j++){
            //cout<<i<<' '<<j<<' '<<a[i]*(i-j+1)-suf[i]+suf[j+1]<<endl;
            if(a[i]*(i-j+1)-suf[j]+suf[i+1]<=m){
                ans = max(ans, i-j+1ll);
                break;
            }
        }
    }cout<<ans<<endl;
}/*
5 8
-3 -1 2 2 7
80pts
*/