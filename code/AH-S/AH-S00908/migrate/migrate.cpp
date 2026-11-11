#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, a[N];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        int g = d / (a[2] - a[1]);
        cout << n * (g - 1) - 3 * g * (g - 1) / 2;
    }
    return 0;
}
