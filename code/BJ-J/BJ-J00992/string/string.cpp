#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 200005
ll a[maxn];
char v[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0;
    cin >> n;
    ll k=0;
    for(ll i=1;i<=n;i++){
        char d;
        cin >> a[i] >> d;
        for(ll j=1+k;j<=a[i]+k;j++){
            v[j] = d;
        }
        k+=a[i];
    }
    for(ll i=1;i<=n;i++){
        ll l=i,r=n-i+1;
        if(v[l]!=v[r]){
            ans++;
        }
    }
    cout << ans/2;
    return 0;
}
