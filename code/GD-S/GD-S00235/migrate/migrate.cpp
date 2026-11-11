#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAXN = 2e6 + 5;
int n; ll D, a[MAXN];
int nxt[MAXN], nxt1[MAXN], nxt2[MAXN], to[MAXN], f[MAXN][2];

void solve(){
    cin >> n >> D;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        f[i][0] = f[i][1] = 0;
    }
    for(int i = 1, j = 0; i <= n; ++i){
        while(j < n && a[j + 1] - a[i] <= D) j++;
        nxt[i] = j;
    }
    for(int i = 2, j = 0; i <= n; ++i){
        while(j < n && a[j + 1] - a[i - 1] <= D) j++;
        nxt1[i] = j;
    }
    for(int i = 3, j = 0; i <= n; ++i){
        while(j < n && a[j + 1] - a[i - 2] <= D) j++;
        nxt2[i] = j;
    }
    for(int i = 1; i <= n; ++i){
        nxt1[i] = min(max(nxt1[i], i), nxt[i]);
        nxt2[i] = min(max(nxt2[i], i), nxt[i]);
        to[i] = nxt1[i] - nxt2[i];
    }
    // for(int i = n; i >= 1; --i){
    //     if(nxt[i] == i) continue;
    //     if(i >= 1 && a[nxt[i] - 1] - a[i - 1] <= D){
            
    //     }
    // }
    ll ans = 0;
    for(int i = n; i >= 1; --i){
        if(nxt[i] == i) continue;
        int now = 0, lst = nxt[i], lst1 = i;
        ans += to[nxt[i]];
        // cout << i << ' ' << nxt[nxt[i]] << ' ' << nxt1[nxt[i]] << '\n';
        for(int j = nxt[nxt[i]] + 1; j <= min(nxt[nxt[i]] + 1, n); ++j){
            if(a[j] - a[lst] > D){
                if(lst - 1 >= 1 && a[nxt[lst]] - a[lst - 1] <= D){
                    now++;
                    if(lst1 != i && a[lst - 1] - a[lst1 - 1] <= D) break;
                }
                if(lst - 2 >= 1 && a[nxt[lst]] - a[lst - 2] <= D) break;
                if(now >= 2) break;
                lst1 = lst; lst = nxt[lst];
                ans += f[nxt[i]][now];
                // cout << "ans: " << i << ' ' << nxt[i] << ' ' << now << '\n';
                break;
            }
            if(a[j] - a[lst] > D) break;
            // int res = 0;
            // if(lst - 1 >= 1 && a[j] - a[lst - 1] <= D){
            //     res++;
            //     // if(lst1 != i && a[lst - 1] - a[lst1 - 1] <= D) res++;
            // }
            // if(lst - 2 >= 1 && a[j] - a[lst - 2] <= D) res++;
            // if(now + res == 1) ans++, cout << i << ' ' << j << ' ' << now << ' ' << res << '\n';
        }

        now = 0, lst = nxt[i], lst1 = i;
        if(a[nxt[i] - 1] - a[i - 1] > D){
            f[i][0] = to[nxt[i]];
        }
        for(int j = nxt[nxt[i]] + 1; j <= min(nxt[nxt[i]] + 1, n); ++j){
            if(a[j] - a[lst] > D){
                if(a[nxt[i] - 1] - a[i - 1] > D){
                    // cout << i << ' ' << f[i][0] << ' ' << to[nxt[i]] << ' ' << nxt1[i] << ' ' << nxt2[i] << '\n';
                    f[i][0] = to[nxt[i]];
                }else f[i][0] = 0;
                if(lst - 1 >= 1 && a[nxt[lst]] - a[lst - 1] <= D){
                    now++;
                    if(a[lst - 1] - a[lst1 - 1] <= D) break;
                }
                if(lst - 2 >= 1 && a[nxt[lst]] - a[lst - 2] <= D) break;
                if(now >= 2) break;
                lst1 = lst; lst = nxt[lst];
                f[i][0] += f[nxt[i]][now];
                break;
            }
            if(a[j] - a[lst] > D) break;
            // int res = 0;
            // if(lst - 1 >= 1 && a[j] - a[lst - 1] <= D){
            //     res++;
            //     if(a[lst - 1] - a[lst1 - 1] <= D) res++;
            // }
            // if(lst - 2 >= 1 && a[j] - a[lst - 2] <= D) res++;
            // if(now + res == 1) f[i][0]++;//, cout << "f0: " << i << ' ' << j << ' ' << now << ' ' << res << '\n';
        }

        now = 1, lst = nxt[i], lst1 = i;
        f[i][1] = nxt[nxt[i]] - nxt1[nxt[i]];
        for(int j = nxt[nxt[i]] + 1; j <= min(nxt[nxt[i]] + 1, n); ++j){
            if(a[j] - a[lst] > D){
                if(lst - 1 >= 1 && a[nxt[lst]] - a[lst - 1] <= D){
                    now++;
                    break;
                    if(a[lst - 1] - a[lst1 - 1] <= D) break;
                }
                if(lst - 2 >= 1 && a[nxt[lst]] - a[lst - 2] <= D) break;
                if(now >= 2) break;
                lst1 = lst; lst = nxt[lst];
                f[i][1] += f[nxt[i]][now];
                break;
            }
            if(a[j] - a[lst] > D) break;
            // int res = 0;
            // if(lst - 1 >= 1 && a[j] - a[lst - 1] <= D){
            //     res++;
            //     if(a[lst - 1] - a[lst1 - 1] <= D) res++;
            // }
            // if(lst - 2 >= 1 && a[j] - a[lst - 2] <= D) res++;
            // if(now + res == 1) f[i][1]++;//, cout << "f1: " << i << ' ' << j << ' ' << now << ' ' << res << '\n';
        }
        // cout << i << ' ' << f[i][0] << ' ' << f[i][1] << '\n';
    }
    cout << ans << '\n';
}

signed main(){
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int _, T; cin >> _ >> T; while(T--) solve();

    return 0;
}