#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], pre[N];

bool check(int x){
    for(int i = x;i <= n;i++){
        int cnt = a[i] * x - pre[i] + pre[i - x];
        if(cnt <= m) return true;
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
    int l = 0, r = n, ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
