#include<bits/stdc++.h>
#define int long long
#define fo(i, l, r) for(int i = (l); i <= (r); ++i)
using namespace std;
int n, m, a[500005], s[500005];
signed main(){
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m; fo(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n); fo(i, 1, n) s[i] = s[i - 1] + a[i];
    int ans = 0;
    fo(i, 1, n){
        int l = 1, r = i, res;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans << '\n';
    return 0;
}
// g++ crystal.cpp -o crystal -O2 -std=c++14 -static