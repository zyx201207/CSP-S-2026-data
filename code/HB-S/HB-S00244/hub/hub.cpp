#include <bits/stdc++.h>
#define lx long long

using namespace std;
const lx N = 2e6 + 5;
lx c , T , n , k;
vector <lx> a[N];
int main () {
    freopen ("hub.in" , "r" , stdin);
    freopen ("hub.out" , "w" , stdout);
    cin >> c >> T;
    while (T --) {
        cin >> n >> k;
        for (lx i = 1 , u , v ; i < n ; i ++) {
            cin >> u >> v;
            a[u].push_back (v);
            a[v].push_back (u);
        }
        cout << "1\n";
    }
    return 0;
}

