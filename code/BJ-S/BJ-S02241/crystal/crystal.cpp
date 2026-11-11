#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], ans = 0;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long i = 1, j = 1;
    long long sum = 0;
    while(i <= n){
        sum += (i-j) * (a[i] - a[i-1]);
        while(sum > m){
            j++;
            sum -= a[i] - a[j];
        }
        ans = max(ans, i - j + 1);
        i++;
    }
    cout << ans << '\n';
    return 0;
}