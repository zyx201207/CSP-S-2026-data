#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[500010];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    ll ans = 0;
    ll c=0;
    for(int i = 0, j = 1; i<=n&&j<=n; j++){
        ll len = j-i;

        c += (len-1) * (a[j] - a[j-1]);
        while(i < j && c > m){
            c -= a[j] - a[i+1];
            i++;
        }
        len = j-i;
        ans = max(ans, len);
        //cout << i << " " << j << endl;
        //cout << c << endl;
    }
    cout << ans << endl;
    return 0;
}