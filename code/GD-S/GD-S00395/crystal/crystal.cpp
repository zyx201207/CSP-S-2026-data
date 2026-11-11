#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int n, m, a[N], s[N], ans;

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    for(int i = 1, lstj = 1; i <= n; ++i){
        int L = 0, R = i, mid;
        while(lstj < i && a[i] * (i - lstj + 1) - (s[i] - s[lstj - 1]) > m) ++lstj;
        ans = max(ans, i - lstj + 1);
    }
    cout << ans;
    return 0;
}