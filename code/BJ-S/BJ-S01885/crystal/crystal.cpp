#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
ll a[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ll ans = 1;
    for(int i = 1; i<=n; i++){
        ll j = i-1, x = m;
        ll sum = 1;
        while(j>0&&a[i]-a[j]<=x){
            x-=(a[i]-a[j]);
            j--;
            sum++;
        }
        ans = max(sum, ans);
    }
    cout << ans;
    return 0;
}
