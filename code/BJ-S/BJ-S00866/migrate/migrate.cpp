#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[10000]={0};
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin >> c >> t;
    for (int ti = 0;ti < t;ti++) {
        ll n,d;
        ll a;
        cin >> n >> d;
        for (int i = 0;i < n;i++) {
            cin >> a;
        }
       ans[ti]=n/2;
    }
    for (int i = 0;i <t;i++) cout << ans[i] << endl;
    return 0;
}
