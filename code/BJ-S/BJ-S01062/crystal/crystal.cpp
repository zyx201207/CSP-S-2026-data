#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N] , b[N];
signed main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    for (int i = 1;i <= n;i++) b[i] = b[i - 1] + a[i];
    int ans = 0;
    for (int i = 1 , j = 1;i <= n;i++){
        while ((i - j + 1) * a[i] - (b[i] - b[j - 1]) > m) ++j;
        ans = max(ans , i - j + 1);
    }
    cout << ans << '\n';
    return 0;
}