#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> p;
ll n, m, ans = 0;
void dfs(ll now, ll dep, ll cnt){
    if(cnt == m) {
        ans = max(ans, now);
        return;
    }
    if(dep > n || n - dep < m - cnt - 1) return;
    dfs(now & p[dep], dep + 1, cnt + 1);
    dfs(now, dep + 1, cnt);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    p.resize(n + 5, 0);
    ll maxn = 0;
    for(ll i = 1; i <= n; i ++){
        cin >> p[i];
        maxn = max(maxn, p[i]);
    }
    if(m == 1) {
        for(ll i = 1; i <= n; i ++) ans = max(ans, p[i]);
        cout << ans << '\n';
    }else if(m == n) {
        ans = p[1];
        for(ll i = 2; i <= n; i ++) ans &= p[i];
        cout << ans << '\n';
    }else if(n <= 20) {
        for(ll i = 1; i <= n; i ++) dfs(p[i], i + 1, 1);
        cout << ans << '\n';
    }else if(m == 2) {
        for(ll i = 1; i <= n; i ++)
            for(ll j = i + 1; j <= n; j ++)
                ans = max(ans, p[i] & p[j]);
    } else if(m == n - 1){
        vector<ll> anss(n + 5, p[1]);
        anss[1] = p[2];
        for(ll i = 2; i <= n; i ++) {
            for(ll j = 1; j <= n; j ++) {
                if(i == j) continue;
                anss[j] &= p[i];
            }
        }
        sort(anss.begin() + 1, anss.begin() + 1 + n);
        cout << anss[1] << '\n';
    } else cout << 0;
    return 0;
}