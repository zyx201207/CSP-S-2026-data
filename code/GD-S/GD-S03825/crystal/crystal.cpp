#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 550000;
ll n, m, a[N], pre[N];
int check(int x){
    for(int i = x; i <= n; i++) if(m >= a[i] * x - pre[i] + pre[i - x]) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    pre[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n, ans = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << flush;
}
