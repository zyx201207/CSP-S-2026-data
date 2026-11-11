#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in", "r", stdin); // dont forget to check file name
    freopen("crystal.out", "w", stdout);

    ll N, M;
    cin>>N>>M;
    vector<ll> a(N);
    vector<ll> asum(N, 0);
    for(ll i=0;i<N;i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    asum[0] = a[0];
    for(ll i=1;i<N;i++) {
        asum[i] = asum[i-1] + a[i];
    }
    ll ans = 1;
    for(ll i=1;i<N;i++) {
        if(a[i]*i*1LL-(asum[i]-a[i])<=M){
            ans++;
        }
    }
    cout<<ans;
    return 0;
    // why I WA on example4? I cant understand.
}