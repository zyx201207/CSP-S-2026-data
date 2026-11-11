#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> a;

bool cmp(ll a,ll b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),cmp);
    ll ans = LLONG_MIN;
    ll l = 0,r = 0;
    ll sum = a[0];
    while(r<n){
        if(sum+m>=(r-l+1)*a[r]){
            ans = max((r-l+1),ans);
            r++;
            if(r>=n) break;
            sum+=a[r];
        }else{
            sum-=a[l];
            l++;
        }
    }
    cout << ans;
}
