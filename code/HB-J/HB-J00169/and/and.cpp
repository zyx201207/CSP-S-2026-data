#include<bits/stdc++.h>
using namespace std;
bool mp[200005][31];
int a[200005];
int t[200005];
bool chose[200005];int n, m;
int ans[30];
inline int tob(int i) {
    int x = a[i];
    int cnt = 0;
    while (x){
        mp[i][30 - ++cnt + 1] = x%2;
        x/=2;
    }
    t[i] = cnt;
    return cnt;
}
inline bool solve(int d) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {//cout << t[i] << ' ' << 30 -d + 1 << ' ';
        if (t[i] < 30 - d  + 1|| !chose[i]) {
            continue;
        }
        if (mp[i][d] == 1) {
            cnt++;
        }
        
    }
    
    // cout << chose[1] << endl;
    // cout << cnt << endl;
    if (cnt >= m) {
        for (int i = 1; i <= n; i++) {
            
            if (mp[i][d] == 1 && chose[i]) {
                chose[i] = true;
            }else chose[i] = false;
        }
        ans[d] = 1;
        return true;
    }
    ans[d] = 0;
    return false;

}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    // freopen("text.in", "r", stdin);
    // freopen("mycode.out", "w", stdout);
    memset(chose, true, sizeof chose);
    cin >> n >> m;
    int maxcnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxcnt = max(maxcnt, tob(i));
    }
    // cout <<maxcnt << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 30 - maxcnt + 1; j <= 30; j++) {
    //         cout << (int)mp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for (int i = 30 - maxcnt + 1; i <= 30; i++) {
         solve(i);
    }
    // for (int i = 1; i<= 30; i++) {
    //     cout << ans[i] << ' ';
    // }
    int nowpow = 1;
    int out = 0;
    for (int i = 30; i >= 30 - maxcnt + 1; i--) {
        out += ans[i] * nowpow;
        nowpow *=2;
    }
    cout << out;
    return 0;
}
/*4 2
3 15 12 12*/