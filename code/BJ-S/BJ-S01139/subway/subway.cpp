#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in", r, stdin);
    freopen("subway.out", w, stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    int a[m + 5];
    for(int i = 1;i <= n;i++) cin >> a[i];
    int f; cin >> f;
    int b[f + 5], t1[f + 5];
    for(int i = 1;i <= f ;++i) cin >> b1[i] >> t1[i];
    int g; cin >> g;
    int b2[g + 5], t2[g + 5];
    for(int i = 1;i <= g ;++i) cin >> b2[i] >> t2[i];
    int x[q + 5], y[q + 5];
    for(int i = 1;i <= q;++i){
        cin >> x[i] >> y[i];
    }
    int h = max(f, g);
    int b[h + 5];
    int l = 1;
    for(int i = 1;i <= h;++i){
        if(b1[i] == b2[i]) b[l] = b1[i];
        l++;
    }
    for(int i = 1;i <= q;i++){
        if(n >= m + 34) b[i] += b1[i];
    }
    for(int i = 1;i <= l;i++) cout << b[i] + b1[i] + b2[i] + t1[i] << endl;
    return 0;
}