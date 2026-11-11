#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5 + 5;
pair <int, char> p[N], q[N];
int n; long long ans;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int ai; char ci;
        cin >> ai >> ci;
        p[i] = {ai, ci};
    }
    for(int i = 1; i <= n; i++) q[i] = p[i];
    reverse(q + 1, q + n + 1);
    int l = 1, r = 1;
    while(l <= n && r <= n) {
        auto [a1, c1] = p[l];
        auto [a2, c2] = q[r];
        int tmp = min(a1, a2);
        if(c1 != c2) ans += 1ll * tmp;
        if(a1 < a2) {
            l++;
            q[r].first -= tmp;
        } else if(a1 > a2) {
            r++;
            p[l].first -= tmp;
        } else {
            l++; r++;
        }
    }
    cout << (ans >> 1) << "\n";
    return 0;
}