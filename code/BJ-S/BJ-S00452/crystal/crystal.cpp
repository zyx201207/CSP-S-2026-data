#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;
ll n, m, a[maxn], b[maxn];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1;i <= n;i++) b[i] = b[i-1] + a[i];
    ll l = 1, r = 1, ans = 0;
    while(true){
        if(l > r || r > n) break;
        ll sum = b[r] - b[l-1], len = r - l + 1;
        if(sum + m >= len * a[r]){
            ans = max(ans, len);
            r++;
        }
        else l++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
