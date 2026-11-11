#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m;
int a[N];
int nxt[N];
unordered_set<int> wait;
int ind[M];
int ans[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        if (wait.count(a[i])) {
            nxt[ind[a[i]]] = i;
            ind[a[i]] = i;
        }
        else {
            wait.insert(a[i]);
            ind[a[i]] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        int p = i;
        int lastp = p;
        while (p <= n) {
            if (nxt[p] != 0) p = nxt[p];
            else {
                ans[a[p]]++;
                p++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
