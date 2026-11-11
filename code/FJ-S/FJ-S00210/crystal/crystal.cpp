#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
#define int long long 
const int N = 5e5 + 5;
int n, a[N], s[N], m, ans = 1;
inline int get_l(int L, int R, int val){
    int l = L, r = R, res = R;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(val * (R - mid + 1) - (s[R] - s[mid - 1]) <= m) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;
}
signed main(){
    FILE("crystal");
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i=1;i<=n;i++) s[i] = s[i - 1] + a[i];
    for(int i=2;i<=n;i++){
        int L = get_l(1, i, a[i]);
        ans = max(ans, i - L + 1);
    } cout << ans;
    return 0;
}