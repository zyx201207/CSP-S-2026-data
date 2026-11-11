#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e6 + 10;
ll n, a[N];
ull d;

int main(){
    freopen("migrate4.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        bool flag = true;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if(i >= 3){
                if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = false;
            }
        }
        if(flag){
            int k = a[2] - a[1];
            ll ans = 0;
            for (int i = 2;i <= n;i += 2){
                int p = i / 2, q = i / 2 - 1;
                if(q * k > d) break;
                if(a[i] - a[1] <= d) continue;
                if(a[i] - a[1] >= 2 * d) break;
                
                ans += (n + 1 - i);
            }
            cout << ans << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}