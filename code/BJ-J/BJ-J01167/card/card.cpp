#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], b[N], tg[M], ans[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i], b[i] = 1;
        tg[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(i != tg[a[i]]) b[tg[a[i]]] += b[i];
        else b[tg[a[i]] + 1] += b[i], ans[a[i]] = b[i];
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
}
