#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], last[M], h[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = n; i > 0; i -- ) {
        if(last[a[i]] != 0) continue;
        last[a[i]] = i;
    }
    for(int i = 1; i <= n; i ++ ) {
        int id = i;
        while(id <= n) {
            if(last[a[id]] == 0) {
                h[a[id]] ++ ;
                id ++ ;
                continue;
            }
            h[a[id]] ++ ;
            id = last[a[id]] + 1;
        }
    }
    for(int i = 1; i <= m; i ++ ) cout << h[i] << " ";
    return 0;
}

