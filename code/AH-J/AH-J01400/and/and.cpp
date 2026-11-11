
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x, ll y){
    return x > y;
}
ll a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    ll ans = a[1];
    for(int i = 2; i <= m; i++){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
