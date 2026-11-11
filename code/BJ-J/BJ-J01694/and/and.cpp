#include <bits/stdc++.h>
using namespace std;
struct node {
    int a, t;
};
int n, m, maxx = -1;
bool cmp(node x, node y) {
    if(x.t != y.t) return x.t > y.t;
    return x.a > y.a;
}
int builtin_popcount(int x) {
    int inc = 0;
    while(x != 0) {
        inc += x % 2;
        x /= 2;
    }
    return inc;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    node num[200005];
    for(int i = 1; i <= n; i++) {
        cin >> num[i].a;
        num[i].t = builtin_popcount(num[i].a);
    }
    sort(num + 1, num + n + 1, cmp);
    int cnt = num[1].a;
    for(int i = 2; i <= m; i++) {
        cnt = cnt & num[i].a;
    }
    cout << cnt << endl;
    return 0;
}
