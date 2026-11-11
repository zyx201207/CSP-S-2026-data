#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    int l = 1, r = n;
    long long ans = 0;
    while (l < r){
        while (a[l] > 0){
            a[l] -= a[r];
            ans += a[r] * (c[l] != c[r]);
            a[r] = 0;
            r--;
        }
        if (a[l] < 0){
            r++;
            a[r] += -a[l];
            ans -= a[r] * (c[l] != c[r]);
        }
        l++;
    }
    cout << ans << endl;
    return 0;
}
