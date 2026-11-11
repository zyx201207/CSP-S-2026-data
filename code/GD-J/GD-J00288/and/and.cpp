#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 200005;
const int sq = 31;
int a[maxn];
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = sq - 1;i >= 0;i--){
        int now = (1ll << i) + ans, cnt = 0;
        for(int j = 1;j <= n;j++){
            if((a[j] & now) == now) cnt++;
        }
        if(cnt >= m) ans = now;
    }
    cout << ans;
    return 0;
}