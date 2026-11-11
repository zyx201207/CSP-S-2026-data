#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], b[N], ans = -1e8;
int main(){
    //freopen("crystal.in", "r", stdin);
    //freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(n <= 5000){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++) b[j] = labs(a[j] - a[i]);
            ll cnt = 0;
            sort(b+1, b+n+1);
            ll t = m;
            for(int j=1; j<=n; j++){
                t -= b[j];
                if(t < 0) break;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        cout << ans;
    }
    else{
        cout << m / (a[2] - a[1]);
    }
    return 0;
}
