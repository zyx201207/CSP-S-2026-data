#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m, a[500005];
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){





        if(a[i] = a[i + 1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}