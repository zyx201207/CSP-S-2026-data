#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a[maxn], maxx, s[maxn], ans;
int find(int x){
    int l = 1, r = x, res= 0;
    while(l <= r && l > 0 && r > 0 && l <= x && r <= x){
        int mid = (l + r) >> 1;
        if((a[x] * (x - mid + 1)- (s[x] - s[mid - 1])) <= m){
            res = mid; r = mid - 1;
        }
        else l = mid + 1;
    }
    if(l <= 0 || r <= 0) return x;
    return x - res + 1;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++){
        ans = max(ans, find(i));
    }
    cout << ans;
    return 0;
}
