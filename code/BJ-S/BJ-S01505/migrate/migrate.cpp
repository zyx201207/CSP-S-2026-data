#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NR = 2e6 + 5;
int n, N;
ll d, x[NR], x0[NR];
int lft[NR], rgt[NR], pre[NR], nxt[NR];
ll ans;
int a[NR], b[NR], tot1, tot2;
ll bit[NR];
void add(int i, ll v){
    while (i <= n){
        bit[i] += v;
        i += (i & -i);
    }
}
ll gs(int i){
    ll res = 0;
    while (i){
        res += bit[i];
        i -= (i & -i);
    }
}
void sol(int lll, int rrr){
    n = rrr - lll + 1;
    for (int i = 1; i <= n; i++){
        x[i] = x0[lll + i - 1];
        bit[i] = 0;
    }
    int j = 1;
    for (int i = 1; i <= n; i++){
        while (x[i] - x[j] > d) j++;
        pre[i] = j;
    }
    j = n;
    for (int i = n; i >= 1; i--){
        while (x[j] - x[i] > d) j--;
        nxt[i] = j;
    }
    for (int i = 1; i <= n; i++){
        if (pre[i] < i && nxt[pre[i]] == i){
            lft[i] = lft[pre[i]] + 1;
        }else{
            lft[i] = 0;
        }
        for (int j = pre[i] + 1; j < i; j++){
            if (nxt[j] == i) lft[i]++;
        }
    }
    for (int i = n; i >= 1; i--){
        if (nxt[i] > i && pre[nxt[i]] == i){
            rgt[i] = rgt[nxt[i]] + 1;
        }else{
            rgt[i] = 0;
        }
        for (int j = i + 1; j < nxt[i]; j++){
            if (pre[j] == i) rgt[i]++;
        }
    }
    for (int l = 1; l <= n; l++){
        for (int r = l; r <= n; r++){
            int pr = pre[r], nx = nxt[l];
            if (l < pr && pr == nx - 1 && nx < r){
                ans++;
                if (pre[pr] == l)
                    ans += 1ll * lft[l];
                if (nxt[nx] == r)
                    ans += 1ll * rgt[r];
                if (pre[pr] == l && nxt[nx] == r)
                    ans += 1ll * lft[l] * rgt[r];
            }
        }
    }
}
void test(){
    cin >> N >> d;
    ans = 0;
    for (int i = 1; i <= N; i++){
        cin >> x0[i];
    }
    int ver = 1;
    for (int i = 2; i <= N; i++){
        if (i > 1 && x0[i] - x0[i - 1] > d){
            sol(ver, i - 1);
            ver = i;
        }
    }
    sol(ver, N);
    cout << ans << endl;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _ >> _;
    while (_--){
        test();
    }
    return 0;
}
/**/
