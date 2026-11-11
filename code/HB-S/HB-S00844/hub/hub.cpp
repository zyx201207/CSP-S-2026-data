#include<bits/stdc++.h>
using namespace std;
const int M = 2e6 + 10;
struct FC{
    int st, en;
    bool operator < (const Fc &f) const{
        return st < f.st;
    }
}a[M];
int b[M], n, m, t, c[M];
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        cin >> a[i].st >> a[i].en;
        b[a[i].st]++;
        b[a[i].en]++;
    }
    for(int i = 1; i <= n; i++){
        c[b[a[i].st]] = i;
    }
    cout << n / m - 1;
    return 0;
}
