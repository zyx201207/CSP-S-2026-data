#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

const int maxn = 1e6 + 10, mod = 998244353;

ll n, m;
ll a[maxn];

int main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    int pos = 1;
    ll need = 0;
    int ans = 1;
    for(int i = 2; i <= n; i ++){
        need += (i - pos) * 1ll * (a[i] - a[i - 1]);
        while(need > m){
            need -= a[i] - a[pos];
            pos ++;
        }
        ans = max(ans, i - pos + 1);
    }

    cout << ans << endl;

    return 0;
}
//Oct31==Dec25?