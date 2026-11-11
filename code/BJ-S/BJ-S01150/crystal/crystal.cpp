#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m, a[500005], ans, qzsum[500005];

bool check(ll l, ll r){
    return (r-l+1)*1ll*a[r]-qzsum[r]+qzsum[l-1] <= m;
}

void ef(ll lst){
    ll l = 1, r = lst, mid;
    while(l <= r){
        mid = l+(r-l)/2;
        if(check(mid, lst)){
            ans = max(ans, lst-mid+1);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return;
}

int main(){
    freopen("crystal.in" , "r", stdin );
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    for(ll i = 1; i <= n; i++) qzsum[i] = qzsum[i-1]+a[i];
    for(ll r = 1; r <= n; r++){
        ef(r);
    }
    cout << ans;
    return 0;
}
