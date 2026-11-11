#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    string s = "";
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a;char c;
        cin>>a>>c;// AC!
        for(ll j=1;j<=a;j++)s += c;
    }
    ll ans = 0;n = s.size();
    for(ll i=0;i<n/2;i++)if(s[i] != s[n-i-1])ans ++;
    cout<<ans<<'\n';
    return 0;
}