#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e5 + 9;
int n; ll m, ans;
ll a[N], s[N];

double Time(){
    return (double)clock()/CLOCKS_PER_SEC;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i){
        s[i] = s[i-1] + a[i];
    }
    for(ll i=1; i<=n; ++i){
        ll l = 1, r = i, res = i;
        while(l<=r){
            ll mid = l + r >> 1;
            ll sum = s[i] - s[mid-1];
            ll need = a[i] * (i-mid+1);
            if(need-sum<=m) r = mid - 1, res = mid;
            else l = mid+1;
        }ans = max(ans, i-res+1);
    }cout << ans << endl;
    // cerr<<Time()<<'s'<<endl;
}