#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    printf("%d", a[n-m]);
    return 0;
}