#include <bits/stdc++.h>
using namespace std;
typedef int long long;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll n, d;
    cin >> n >> d;
    int a[n + 5] = {};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll c = a[1] - a[0];
    if (d < c){
        cout << "0\n";
        return 0;
    }
    cout << n - 2 << '\n';
    return 0;
}
