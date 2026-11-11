#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mn = 5e5 + 5;
int a[mn], s[mn], n, m, ans = 0;
bool check(int rr, int ll){
    int tt = a[rr] * (rr - ll) - s[rr - 1] + s[ll - 1];
    if(tt <= m) return true;
    return false;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    s[0] = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++){
		s[i] = a[i] + s[i - 1];
	}
    for(int i = 1; i <= n; i ++){
        int l = 1, r = i;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(i, mid)){
                ans = max(ans, i - mid + 1);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
