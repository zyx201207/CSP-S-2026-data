#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5005, maxn = 2e6 + 50;

int ID, T, n, lst[maxn], f[N][N];
ll d, x[maxn], g[N][N], sum[N][N];

void solve1(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    if(x[n] - x[1] <= d) return cout << "0\n", void();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) f[i][j] = g[i][j] = sum[i][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        lst[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
    }
    for(int i = 1; i <= n; i++){
        f[i][i] = 0, sum[i][i] = g[i][i] = 1;
        for(int j = i + 1; j <= n; j++){
            int p = max(lst[j], i);
            f[i][j] = (p < j ? f[i][p] + 1 : -1);
        }
    }
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            if(x[r] - x[l] <= d) g[l][r] = 1;
            else {
                int p = lst[r], L = p, R = r - 1, res = p;
                while(L <= R){
                    int mid = (L + R) >> 1;
                    if(f[l][mid] == f[l][p]) res = mid, L = mid + 1;
                    else R = mid - 1;
                }
                g[l][r] = sum[l][res] - sum[l][p - 1];
            }
            sum[l][r] = sum[l][r - 1] + g[l][r];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++) if(g[i][j] == 2) ans++;
    }
    cout << ans << '\n';
}

void solve2(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    ll D = x[2] - x[1];
    if(d < 2ll * D) return cout << "0\n", void();
    ll X = 2ll * (d / D);
    // cerr << D << ' ' << X << ' ' << n << endl;
    cout << max(0ll, (ll)n - X + 1) << '\n';
}

void solve3(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    if(x[n] - x[1] <= d) return cout << "0\n", void();
    int p = 0;
    for(int i = 2; i < n; i++){
        if(x[i] - x[1] <= d && x[n] - x[i] <= d){ p = i; break; }
    }
    if(!p) return cout << -1 << '\n', void();
    ll ans = 0, cp = 0, cp1 = 0;
    for(int i = p + 1; i <= n; i++){
        lst[i] = lower_bound(x + 1, x + p, x[i] - d) - x;
        if(lst[i] == p) cp++;
        if(lst[i] == p - 1) cp1++;
    }
    for(int i = 1, to = p; i < p; i++){
        while(to + 1 <= n && x[to + 1] - x[i] <= d) to++;
        if(to == p){
            ans += cp1;
        } else if(to == p + 1){
            ans += cp;
        } else break;

    }
    cout << ans << '\n';
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> ID >> T;
    while(T--){
        if(ID <= 10) solve1();
        else if(ID == 11 || ID == 12) solve2();
        else if(ID == 13 || ID == 14) solve3();
        // solve3();
    }
    return 0;
}