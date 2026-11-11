#include <bits/stdc++.h>

using namespace std;

#define int long long


#define fi first
#define se second
#define mkp make_pair

const int N = 5e5 + 20;
int n, m;
int a[N], s[N];

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int ans = 0; 
    for(int i = 1; i <= n; ++i){
        int l = 1, r = i, res = i;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m){
                r = mid - 1;
                res = mid; 
            }
            else{
                l = mid + 1; 
            }
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans << '\n';

    return 0; 
}
