#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
ll a[MAXN];
ll sum[MAXN];
ll b[MAXN];
bool cmp(ll x, ll y){
    return x>y;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n, cmp);
    for(ll i=1;i<=n;i++){
        // cout << a[i] << " ";
        sum[i]=sum[i-1]+a[1]-a[i];
    }
    ll ans=0;
    a[0]=a[1];
    for(ll i=1;i<=n;i++){
        for(ll j=n;j>=i;j--){
            sum[j]-=(j-i+1)*(a[i-1]-a[i]);
            if(sum[j]<=m){
                ans=max(ans, j-i+1);
                break;
            }
        }
        // cout << sum[i] << endl;
    }  
    cout << ans;
}