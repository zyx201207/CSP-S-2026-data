#include <bits/stdc++.h>
using namespace std;
long long l[200010];
long long dg (long long a[], int al, int ar, int zm){ //左右边界，2指数max
    long long p;
    bool flag = false;
    for (int i = zm; i >= 0; i--){
            p = pow(2, i);
        if (a[al] >= p){
            for (int j = al + 1; j <= ar; j++){
                if (a[j] < p) {
                    flag = true;
                    break;
                }
                ar = j;
            }
        }
        if (flag) break;
    }
    if (ar == al + 1) return (a[al] && a[al + 1]);
    else if (ar > al + 1) {
        for (int i = al; i <= ar; i++) a[i] -= p;
        return dg(a, al, ar, p) + p;
    }
    else if (ar < al + 1) {
        return dg(a, al + 1, ar, p);
    }

}
bool cmp (int x, int y){
    if (x > y) return true;
    return false;
}
int main (){
    freopen("and1.in", "r", stdin);
    freopen("and1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int lm = n - 1;
    for (int i = 0; i < n; i++) cin >> l[i];
    sort (l, l + n, cmp);
    //for (int i = 0; i < n; i++) cout << l[i] << endl;
    cout << dg(l, 0, lm, 30);
    return 0;
}

