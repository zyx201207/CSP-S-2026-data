#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define pii pair < int , int >
#define mp(i, j) make_pair(i, j)

// 细节题 需要好好实现
const int N = 2e6 + 5;
ll n, m, a[N], d, nxt[N], vis[N], cl[N];

void solvetask() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    nxt[n] = n;
    for(int i = n - 1; i >= 1; i--) {
        nxt[i] = nxt[i + 1];
        while(a[nxt[i]] - a[i] > d) nxt[i] --;
    }
//    for(int i = 1; i <= n; i++) cout << nxt[i] << " ";
 //   cout << endl;
    ll ans = 0;
    a[0] = a[1] - d - 1;
    for(int i = 1; i <= n; i++) {
   //     cout << "i = " << i << endl;
        memset(cl, 1, sizeof cl);
        int p1 = 0, p2 = 0;
        ll p = i;
        while(p < nxt[p]) {
  //          cout << p2 << " " << p1 << " " << p << endl;
 //           nxt[p2] - nxt[p1] - nxt[p]
            if(cl[p2] || cl[p1]) {
                ans += nxt[p1] - nxt[p2];
                if(!cl[p1]) {
                    cl[nxt[p1]] = 0;
                    if(p1) cl[nxt[p1] - 1] = 0;
                }
                else if(!cl[p2]) {
                    cl[nxt[p2]] = 0;
                    if(p2) cl[nxt[p2] - 1] = 0;
                }
            } else {
                cl[nxt[p]] = cl[nxt[p] - 1] = 0, cl[min(nxt[p] - 2, 0ll)] = 0;
            }
            p1 = max(p, nxt[p] - 1);
            p2 = max(p, nxt[p] - 2);
            p = nxt[p];
 //           cout << "ans = " << ans << endl;
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    int c, T = 1;
    cin >> c >> T;
    while(T --) solvetask();
    return 0;
}
