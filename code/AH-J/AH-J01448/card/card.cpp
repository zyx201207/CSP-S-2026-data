#include <bits/stdc++.h>
using namespace std;
int a[500010], b[500010], t[300010];
int main (){
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            t[a[j]]++;
        }
    }
    for (int i = 1; i <= m; i++){
        cout << t[i] << ' ';
    }
    return 0;
}
