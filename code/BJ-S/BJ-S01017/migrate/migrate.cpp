#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 +10;
int a[maxn];

//A

void solve(){
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    int cha = a[2] - a[1];
    int x = d / cha;
    int sum = 2 * x;
    int ans = 0;
    while (sum <= n){
        ans += n - sum + 1;
        sum += x;
    }
    cout << ans << endl;


}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c,t;
    cin >> c >> t;
    while (t --){
        solve();
    }

}

