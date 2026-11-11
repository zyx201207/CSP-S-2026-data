#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2e5+5;
ll n,m,a[M];
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if (m == 1){
        sort (a+1,a+n+1);
        cout << a[n];
    }
    else if (m == 2){
        ll ans = -1;
        for (int i = 1;i <= n;i++){
            for (int j = i+1;j <= n;j++){
                ans = max(ans,a[i]&a[j]);
            }
        }
        cout << ans;
    }
    else if (m == n){
        ll ans = a[1];
        for (int i = 2;i <= n;i++){
            ans &= a[i];
        }
    cout << ans;
    }
    else {
        ll ans = a[1];
        sort(a+1,a+n+1,cmp);
        for (int i = 2;i <= m;i++){
            ans &= a[i];
        }
    cout << ans;
    }
    return 0;
}