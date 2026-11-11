#include<bits/stdc++.h>
using namespace std;

const int maxm = 5 * 1e5 + 10;
int n, m, sz, a[maxm];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1, j <= sz; j++) [
            if(a[j] == a[i]) {
                sz = i;
            }
        ] 
    }
    for(int i = 1; i <= m; i++) cout << 0 << " ";
    return 0;
}