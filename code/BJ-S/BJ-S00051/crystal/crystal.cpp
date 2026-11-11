#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    int n , m , cnt = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    int sum = 0 , l = 0 , maxn = 0;
    for (int i = 2; i <= n; i++){
        sum += cnt * (a[i] - a[i - 1]);
        while (sum > m && l < i){
            sum -= a[i] - a[l];
            l++;
            cnt--;
        }
        cnt++;
        maxn = max(maxn , cnt);
    }
    cout << maxn;
    return 0;
}
